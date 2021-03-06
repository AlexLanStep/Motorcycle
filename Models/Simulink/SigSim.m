classdef SigSim <  handle & matlab.System & matlab.system.mixin.Propagates
    properties

    end

    properties(DiscreteState)

    end

    % Pre-computed constants
    properties(SetAccess  = private)
        M1 = zeros(51, 1)
        M1count = 51 
        M2 = zeros(29, 1)
        M2count =  29
        M3 =  zeros(15, 1)
        M3count =  15
        
        myFront = struct('front', 0, 'frontCount', 0, 'is_front', false,...
                            'i_tik', 1, 'i_tik_save', 0, 'i_sum_front', 0, ...
                            'i_sum_tek_front', 0, 'i_n_count_ntime', 0,...
                            'is_signal', false,  'i_nCount_tic_null', 70)
        mySigmoid = struct('IsForm', false, 'nCount', 0)
        point = struct('y1', 0, 'y0', 0)
        ind = struct('sig', 0, 'nCount', 0, 'i', 0)
        i, j, k, 
        u_tek, u_delta, u_sm, u_sig_k
        y_old, nEma, alfa_ema
    end
    
    properties(Access  = private)
        
    end

    methods(Access = protected)
        function setupImpl(obj)
            obj.u_tek = 0; 
            obj.u_delta = 0; 
            obj.u_sm = 0;
            set_sig(obj);
            obj.i=0;
            obj.u_sig_k=0;
            obj.myFront.i_nCount_tic_null=70;
            obj.u_sig_k=0.0;
            obj.y_old=0;
            obj.nEma=5;
            obj.alfa_ema=2/(obj.nEma+1);
        end
        
        function y = stepImpl(obj,u)
            if obj.ind.sig==0
                inicial_ind(obj, 1)
            end
            
            get_front(obj, u);
            
            y = 0;
            
            if abs(obj.myFront.i_sum_front) >0 % !!! ????????? ???????
%            if abs(obj.myFront.is_front) >0 % !!! ????????? ???????
                y = step_func3(obj, u);
            else
                y=obj.u_tek;
            end

            
            x=y - obj.y_old;
            y = obj.y_old + obj.alfa_ema*(x);
            obj.y_old=y;
            
        end

        function resetImpl(obj)
        end

    end
    
    methods(Access = private)
        
        function y=get_m(obj)
            obj.ind.i=obj.ind.i + 1; 
            if obj.ind.i> obj.ind.nCount
                y=1.0;
                obj.mySigmoid.IsForm=false;
                return;
            end
            switch max(min(obj.ind.sig, 3), 1)
                case 1
                    y=obj.M1(obj.ind.i);
                case 2 
                    y=obj.M2(obj.ind.i);
                case 3 
                    y=obj.M3(obj.ind.i);
                otherwise                        
                    y=1;
            end
        end
            
        function obj=get_front(obj, u)
            obj.point.y0 = obj.point.y1;
            obj.point.y1 = u;
            obj.myFront.is_front = obj.point.y1 ~= obj.point.y0;
            obj.myFront.i_tik = obj.myFront.i_tik + 1;

            obj.myFront.is_signal = abs(u) > 0 ...
                || (abs(u) == 0 && obj.myFront.i_tik < obj.myFront.i_nCount_tic_null);
            
            if ~obj.myFront.is_front
% ??? ?????? ??????? ????
                
                if obj.myFront.i_tik >= obj.myFront.i_nCount_tic_null
                    obj.myFront.i_sum_front=0;
                end
                 
            elseif obj.point.y1 > obj.point.y0
                obj.myFront.i_tik_save = obj.myFront.i_tik;
 				obj.myFront.i_tik = 1;
 
                if obj.myFront.i_sum_front <= 0
                    obj.myFront.i_sum_front = 1;
                else
                    obj.myFront.i_sum_front = min(obj.myFront.i_sum_front+1, 3);
                end
            else
                obj.myFront.i_tik_save = obj.myFront.i_tik;
 				obj.myFront.i_tik = 1;
                
                if obj.myFront.i_sum_front >= 0
                    obj.myFront.i_sum_front = -1;
                else
                    obj.myFront.i_sum_front = max(obj.myFront.i_sum_front-1, -3);
                end
            end
            
        end
        
        function inicial_ind(obj, i0)
            obj.ind.sig=i0;
            
            switch max(min(obj.ind.sig, 3), 1)
                case 1 
                    obj.ind.nCount=obj.M1count;        
                case 2 
                    obj.ind.nCount=obj.M2count;        
                case 3 
                    obj.ind.nCount=obj.M3count;        
                otherwise                        
                    obj.ind.nCount=obj.M1count;        
                    obj.ind.sig=1;
            end
        end
        
        function set_sig(obj)
            i=0; 
            j=0; 
            k=0;
            obj.ind.sig=0;
            
            kSig=0.01;
            nTime=50; alfa=22;
            nSigStart=fix(nTime/2);
            tsig=(-kSig*nSigStart: kSig: kSig*nSigStart)';
            obj.M1=(1+exp(-tsig.*alfa)).^-1;
            
            nTime=28; alfa=40;
            nSigStart=fix(nTime/2);
            tsig=(-kSig*nSigStart: kSig: kSig*nSigStart)';
            obj.M2=(1+exp(-tsig.*alfa)).^-1;
            
            nTime=14; alfa=80;
            nSigStart=fix(nTime/2);
            tsig=(-kSig*nSigStart: kSig: kSig*nSigStart)';
            obj.M3=(1+exp(-tsig.*alfa)).^-1;
            
        end
        
        function v = step_func3(obj, u)
            obj.u_sig_k = get_m(obj);
            obj.u_tek = obj.u_sm + obj.u_delta * obj.u_sig_k;
            v=obj.u_tek;
            
            if not(obj.myFront.is_front)
                return
            end
            
            if obj.mySigmoid.IsForm
                % ?????????? ???????????? ???
                tfront= min(abs(obj.myFront.i_sum_front),3)
                switch tfront
                    case 1
                        d=find(obj.M1>obj.u_sig_k, 1);
                        obj.u_sig_k = obj.M1(d(1),1);
                        obj.ind.i=d(1);
                        obj.ind.nCount=obj.M1count;        
                        obj.ind.sig=1;
                    case 2
                        d=find(obj.M2>obj.u_sig_k, 1);
                        obj.u_sig_k = obj.M2(d(1),1);
                        obj.ind.i=d(1);
                        obj.u_sig_k = obj.M2(obj.ind.i);
                        obj.ind.nCount=obj.M2count;        
                        obj.ind.sig=2;
                    case 3 
                        d=find(obj.M3>obj.u_sig_k, 1);
                        obj.u_sig_k = obj.M3(d(1),1);
                        obj.ind.i=d(1);
                        obj.u_sig_k = obj.M3(obj.ind.i);
                        obj.ind.nCount=obj.M3count;        
                        obj.ind.sig=3;
                    otherwise                        
                        obj.ind.i=100;
                        obj.u_sig_k =1;
                        obj.ind.nCount=1;        
                        obj.ind.sig=4;
                end
                obj.u_sm = obj.u_tek;
                obj.u_delta = u - obj.u_tek;
                obj.ind.i = 0;
            else
                % ??? ? ???????????
                inicial_ind(obj, abs(obj.myFront.i_sum_front))
                obj.u_sm = obj.u_tek;
                obj.u_delta = u - obj.u_tek;
                obj.ind.i = 0;
            end
            
        end
        
    end
    
end
