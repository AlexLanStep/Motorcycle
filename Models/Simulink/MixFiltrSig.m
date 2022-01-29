<<<<<<< HEAD
classdef MixFiltrSig < handle & matlab.System & matlab.system.mixin.Propagates
=======
classdef MixFiltrSig <   matlab.System  %& matlab.system.mixin.Propagates
>>>>>>> 58925e529482e008a2fc07d6f3504cf55412d7b8
    %handle  & matlab.System & matlab.system.mixin.Propagates

    % Public, tunable properties
    properties

    end

    % Public, non-tunable properties
    properties(Nontunable)

    end

    properties(DiscreteState)

    end
    % Pre-computed constants
    properties(SetAccess  = private)
%        M1 = zeros(51, 1)
%        M1count = 51 
        M1 = zeros(41, 1)
        M1count = 41 
%        M2 = zeros(29, 1)
%        M2count =  29
        M2 = zeros(23, 1)
        M2count =  23
        M3 =  zeros(15, 1)
        M3count =  15
        
        myFront = struct('front', 0, 'frontCount', 0, 'is_front', false,...
                            'i_tik', 1, 'i_tik_save', 0, 'i_sum_front', 0, ...
                            'i_sum_tek_front', 0, 'i_n_count_ntime', 0,...
                            'is_signal', false,  'i_nCount_tic_null', 50)       % 70
        mySigmoid = struct('IsForm', false, 'nCount', 0)
        point = struct('y1', 0, 'y0', 0)
        ind = struct('sig', 0, 'nCount', 0, 'i', 0)
        i=0, j=0, k=0, 
        u_tek=0, u_delta=0, u_sm=0, u_sig_k=0
        y_old=0.0, nEma=0, alfa_ema=0.0, alfa_ema1=0.0
        
    end

    % Pre-computed constants
    properties(Access = private)

    end

    methods
        % Constructor
        function obj = MixFiltrSig(varargin)
            % Support name-value pair arguments when constructing object
            %setProperties(obj,nargin,varargin{:})
<<<<<<< HEAD
            mysetup(obj)
=======
>>>>>>> 58925e529482e008a2fc07d6f3504cf55412d7b8
        end
    end

    methods(Access = protected)
%    methods(Access = public)
        %% Common functions  Инициализация переменных
        function setupImpl(obj)
            obj.u_tek = 0; 
            obj.u_delta = 0; 
            obj.u_sm = 0;
            set_sig(obj);
            obj.i=0;
            obj.u_sig_k=0;
            obj.myFront.i_nCount_tic_null=50;  % 70
            obj.u_sig_k=0.0;
            obj.y_old=0;
            obj.nEma=15;
            obj.alfa_ema=2/(obj.nEma+1);
            obj.alfa_ema1 = 1-obj.alfa_ema;
        end
        
        function y = stepImpl(obj,u)
            if obj.ind.sig==0
                inicial_ind(obj, 1)
            end
            
            get_front(obj, u);
            
            y = 0;
            
            if abs(obj.myFront.i_sum_front) >0 % !!! проверить условия
%            if abs(obj.myFront.is_front) >0 % !!! проверить условия
                y = step_func3(obj, u);
            else
                y=obj.u_tek;
            end
%{            
        формируем EMA 
            y = obj.y_old*obj.alfa_ema1 + obj.alfa_ema*(y);            
%}
            obj.y_old = y;
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end

        %% Backup/restore functions
        function s = saveObjectImpl(obj)
            % Set properties in structure s to values in object obj

            % Set public properties and states
            s = saveObjectImpl@matlab.System(obj);

            % Set private and protected properties
            %s.myproperty = obj.myproperty;
        end

        function loadObjectImpl(obj,s,wasLocked)
            % Set properties in object obj to values in structure s

            % Set private and protected properties
            % obj.myproperty = s.myproperty; 

            % Set public properties and states
            loadObjectImpl@matlab.System(obj,s,wasLocked);
        end

        %% Simulink functions
        function ds = getDiscreteStateImpl(obj)
            % Return structure of properties with DiscreteState attribute
            ds = struct([]);
        end

        function flag = isInputSizeLockedImpl(obj,index)
            % Return true if input size is not allowed to change while
            % system is running
            flag = true;
        end

        function out = getOutputSizeImpl(obj)
            % Return size for each output port
            out = [1 1];

            % Example: inherit size from first input port
            % out = propagatedInputSize(obj,1);
        end

        function [out,out2] = isOutputFixedSizeImpl(obj)
            % Return true for each output port with fixed size
            out = true;
            out2 = true;

            % Example: inherit fixed-size status from first input port
            % out = propagatedInputFixedSize(obj,1);
        end

        function icon = getIconImpl(obj)
            % Define icon for System block
            icon = mfilename('class'); % Use class name
            % icon = 'My System'; % Example: text icon
            % icon = {'My','System'}; % Example: multi-line text icon
            % icon = matlab.system.display.Icon('myicon.jpg'); % Example: image file icon
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
% нет фронта считаем тики
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
            i=0;  j=0;  k=0;
            obj.ind.sig=0;
            
            kSig=0.01;
%            nTime=50; alfa=22;
            nTime=40; alfa=30;  % - пока не работает нужно переделывать
%            матрицу и прочее....
            nSigStart=fix(nTime/2);
            tsig=(-kSig*nSigStart: kSig: kSig*nSigStart)';
            obj.M1=(1+exp(-tsig.*alfa)).^-1;
            
%            nTime=28; alfa=40;
            nTime=22; alfa=50;
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
                % происходит формирование сиг
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
                % сиг с формирована
                inicial_ind(obj, abs(obj.myFront.i_sum_front))
                obj.u_sm = obj.u_tek;
                obj.u_delta = u - obj.u_tek;
                obj.ind.i = 0;
            end
            
        end
        
    end
    
    methods(Static, Access = protected)
        %% Simulink customization functions
        function header = getHeaderImpl
            % Define header panel for System block dialog
            header = matlab.system.display.Header(mfilename('class'));
        end

        function group = getPropertyGroupsImpl
            % Define property section(s) for System block dialog
            group = matlab.system.display.Section(mfilename('class'));
        end
    end
end




