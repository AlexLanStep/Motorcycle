classdef SigmoidMixail  < handle
    properties
        Sigmoids
    end
    
    properties (SetAccess = private)
        fitresult, Ugol
        nTime, alfa, 
        nSig=50
        kSig=0.01

        masPol=[17 110; 18 106; 19 103;  20 99; 21 95; 22 91; 23 88; ...
                 24 84;  25 81;  26 78;  27 75; 28 72; 29 69; 30 66; ...
                 31 64;  32 62;  33 60;  34 58; 35 56; 36 54; 37 52; ...
                 38 51;  39 49;  40 48;  41 47; 42 45; 43 44; 44 43; ...
                 45 42;  46 41;  47 40;  48 39; 49 38; 50 38; 51 37; ...
                 52 36;  53 35;  54 34;  55 33; 56 33; 57 32; 58 31; ...
                 59 31;  60 30;  61 29;  62 29; 63 28; 64 27; 65 27; ...
                 66 26;  67 26;  68 25;  69 25; 70 24; 71 24; 72 24; ...
                 73 23;  74 23;  75 22;  76 22; 77 22; 78 21; 79 21; ...
                 80 21;  81 20;  82 20;  83 20; 84 20; 85 19; 86 19; ...
                 87 19;  88 19;  89 18;  90 18; 91 18; 92 18; 93 18; ...
                 94 17;  95 17;  96 17;  97 17; 98 17; 99 16;100 16]
                 
        myFront
        mySigmoid
        y0, y1, ResultStep, zU
        
    end
    
    methods
        function obj =  SigmoidMixail(nTime_, alfa_)
            switch nargin
               case 1
                    Set(obj, nTime_);
               case 2
                    Set(obj, nTime_, alfa_);
                otherwise
                    Set(obj, 150, 10);                    
            end
            
            Install(obj);
        end        
        
        function obj = Install(obj)
            obj.Sigmoids.nCountSigmoidBasa = length(obj.Sigmoids.SigmoidBasa);
            obj.Sigmoids.nCountSigmoidSum = length(obj.Sigmoids.SigmoidSum);

            obj.myFront.trend=0;
            obj.myFront.front0=0;
            obj.myFront.frontCount=0;
            obj.myFront.U=0;
            obj.myFront.Sum=0;

            obj.mySigmoid.Type = 0; % 0 - "0"; 
                    %1 -Up base sigmoid; 2 -Up sigmoidSum; 
                    %-1 -Boot base sigmoid; 2 -boot sigmoidModif;
            obj.mySigmoid.nCount =  0;
            obj.mySigmoid.Sigmoid=0;
            obj.mySigmoid.smU = 0;
            obj.mySigmoid.IsForm = false;   % формируем sigmoid
                        % false - не выполняется формирование
                        % true - выполняется  формирование 
        end
        
        function obj =  Set(obj, nTime_, alfa_)
            obj.nTime=nTime_;
            switch nargin
               case 2
                   obj.alfa=GetUgol(obj, obj.nTime);      %Sigmoid.
               case 3
                    obj.alfa=alfa_;
                    
                otherwise
                    obj.nTime=30;
                    obj.alfa=GetUgol(obj, obj.nTime);
            end     
            nSigStart=fix(obj.nTime/2);
            tsig=(-obj.kSig*nSigStart: obj.kSig: obj.kSig*nSigStart)';
            obj.Sigmoids.SigmoidBasa=(1+exp(-tsig.*obj.alfa)).^-1;
            obj.Sigmoids.CountTabl=length(obj.Sigmoids.SigmoidBasa);
            FSigmoidSum(obj);
            obj.Sigmoids.SigmoidBasaM=(1-obj.Sigmoids.SigmoidBasa);
            obj.Sigmoids.SigmoidSumM=(1-obj.Sigmoids.SigmoidSum);
        end
        
        function n =GetUgol(obj, x)
            n=obj.masPol(find(obj.masPol(:,1)==fix(x)),2);
            %n=fix(obj.fitresult(x));
        end

        function obj = FSigmoidSum(obj)
            iCountBasa=length(obj.Sigmoids.SigmoidBasa);
            iStep=fix(iCountBasa/4);
            sigmoid1=obj.Sigmoids.SigmoidBasa(iCountBasa-fix(iStep*2.0):iCountBasa-iStep);
            val=sigmoid1(length(sigmoid1));
            sigmoid2=obj.Sigmoids.SigmoidBasa(iStep:iCountBasa)+val;
            obj.Sigmoids.SigmoidSum=[sigmoid1; sigmoid2];
            val0=obj.Sigmoids.SigmoidSum(1);
            if val0~=0
                if val0>0
                    obj.Sigmoids.SigmoidSum=obj.Sigmoids.SigmoidSum-val0;
                else
                    obj.Sigmoids.SigmoidSum=obj.Sigmoids.SigmoidSum+val0;
                end
            end
            vMax=max(obj.Sigmoids.SigmoidSum);
            obj.Sigmoids.SigmoidSum=obj.Sigmoids.SigmoidSum./vMax;
        end
            
        function [front, u] =  dif(obj, y0, y1)
            u=y1 - y0;
            if(y1 == y0)
                front=0; 
                u=0;
                return
            end
            if(y1 > y0)
                if obj.myFront.Sum <0
                    obj.myFront.Sum=0;
                end
                front=1; 
                obj.myFront.Sum = obj.myFront.Sum +1;
            else    %  y1 < y0
                if obj.myFront.Sum >0
                    obj.myFront.Sum=0;
                end
                front=-1; 
                obj.myFront.Sum = obj.myFront.Sum -1;                
            end
        end        

        function InicSignFunc =  InicialSigmoid(obj, y0, y1, rez)
            [InicSignFunc.front, InicSignFunc.u] = dif(obj, y0, y1);
            
            if abs(InicSignFunc.front)==1  
                if abs(obj.myFront.Sum) == 1
                    Set(obj, 50);
                    Install(obj);
                elseif abs(obj.myFront.Sum) == 2
                    Set(obj, 25);
                    Install(obj);
                elseif abs(obj.myFront.Sum) == 3
                    Set(obj, 17);
                    Install(obj);
                end
                
                if obj.mySigmoid.IsForm
                    if abs(obj.myFront.Sum) == 1
                        obj.mySigmoid.nCount= obj.Sigmoids.nCountSigmoidBasa;
                        obj.mySigmoid.Sigmoid=obj.Sigmoids.SigmoidBasa;
                    else
                        obj.mySigmoid.nCount= obj.Sigmoids.nCountSigmoidSum;
                        obj.mySigmoid.Sigmoid=obj.Sigmoids.SigmoidSum;
                    end
                else
                       obj.mySigmoid.nCount= obj.Sigmoids.nCountSigmoidBasa;
                       obj.mySigmoid.Sigmoid=obj.Sigmoids.SigmoidBasa;
                end
                
                obj.myFront.trend=InicSignFunc.front;
                obj.mySigmoid.Type = InicSignFunc.front;

                if ~ obj.mySigmoid.IsForm  
                    obj.mySigmoid.IsForm = true;
                end
                
                obj.myFront.frontCount=1;
                obj.mySigmoid.smU=rez;
                obj.myFront.U=y1 - obj.mySigmoid.smU;
            end
        end
        
        function Result = CalcSignal(obj, y)
            nCount=length(y);
            Result.rez=zeros(nCount, 1);
            Result.rezU=zeros(nCount, 1);
            Result.rez(1)=0;
            Result.rezU(1)=0;
            Result.kRez=0;
            Install(obj);
            
            for i=2:nCount
                InicialSigmoid(obj, y(i-1), y(i),  Result.rezU(i-1));
                if obj.myFront.trend ~= 0
                    if obj.mySigmoid.Type~=0 && obj.mySigmoid.IsForm
                        Result.kRez=obj.mySigmoid.Sigmoid(obj.myFront.frontCount);
                        obj.myFront.frontCount= obj.myFront.frontCount+1;
                        obj.mySigmoid.IsForm=obj.myFront.frontCount <= obj.mySigmoid.nCount;
                    else
                        obj.myFront.frontCount=0;
                        obj.mySigmoid.Type=0;
                        if obj.mySigmoid.Type>0
                            Result.kRez=1;
                        elseif obj.mySigmoid.Type<0
                            Result.kRez=0;
                        end
                    end
                end
                
                Result.rez(i)=Result.kRez;
                Result.rezU(i)=obj.mySigmoid.smU+ Result.rez(i)*obj.myFront.U;
                
            end            
        end
        
        function obj = CalcSignalStep(obj, y)
            obj.y0= obj.y1;            
            obj.y1=y;
            
            InicialSigmoid(obj, obj.y0, obj.y1, obj.zU);
            if obj.myFront.trend ~= 0
                if obj.mySigmoid.Type~=0 && obj.mySigmoid.IsForm
                    obj.ResultStep.kRez=obj.mySigmoid.Sigmoid(obj.myFront.frontCount);
                    obj.myFront.frontCount= obj.myFront.frontCount+1;
                    obj.mySigmoid.IsForm=obj.myFront.frontCount <= obj.mySigmoid.nCount;
                else
                    obj.myFront.frontCount=0;
                    obj.mySigmoid.Type=0;
                    if obj.mySigmoid.Type>0
                        obj.ResultStep.kRez=1;
                    elseif obj.mySigmoid.Type<0
                        obj.ResultStep.kRez=0;
                    end
                end
            end
            obj.zU = obj.mySigmoid.smU+ obj.ResultStep.kRez*obj.myFront.U;
%            z = obj.zU;
        end
        
        function Result = Run(obj, y)
            nCount=length(y);
            Result.rezU=zeros(nCount, 1);
            
            obj.ResultStep.rez=0;
            obj.ResultStep.rezU=0;
            obj.ResultStep.kRez=0;
            
            Install(obj);
            obj.y0=0; 
            obj.y1=0;        
            obj.zU=0;
            for i=2:nCount
                CalcSignalStep(obj, y(i));
                Result.rezU(i)=obj.zU;
            end            
            
        end
    end
end
