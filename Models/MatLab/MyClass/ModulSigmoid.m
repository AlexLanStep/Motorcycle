classdef ModulSigmoid < matlab.System
    % Public, tunable properties
    properties(SetAccess  = public)
        Rwheel = 17*0.0254
        Transfer = 3
        Kreset  = 0.6;      
        sd = 6 
        sdsn = 0.25
        betta = 0.6
        sm_bet = 0.3
        alfa = 1.0 
        sm_alfa = 0.3
        kStd=4;
        alfaExp=0.5;
    end

    % Public, non-tunable properties
    properties(Nontunable)

    end

    properties(DiscreteState)

    end

    % Pre-computed constants
    properties(Access = private)
        d = zeros(6, 101);
        ind = 1;
        dSlipp = zeros(1, 30);
        lSlipp = 0;
        R=0;
        alfa1=0;
        Y0=0;
    end

    methods
        % Constructor
        function obj = ModulSigmoid(varargin)
            % Support name-value pair arguments when constructing object
            setProperties(obj,nargin,varargin{:})
            obj.ind=1;
            obj.R =  obj.Rwheel  *  obj.Transfer;
            
             for i=1:6
                 for j=1:101
                     obj.d(i, j)= CalcSigm(obj, i-1,   j-1);       
                 end
             end            
             
             [i0, j0]  = size(obj.d);
             for k=i0-1:-1:1
%                 disp(k)
                 count = length(obj.d(k, obj.d(k,:)  >  obj.d(k+1, :)));
                 obj.d(k,1:count) = obj.d(k+1,1:count);
             end
             
             obj.lSlipp = length(obj.dSlipp);
             obj.alfa1 = 1-obj.alfaExp;
         end
    end

    methods(Access = protected)
        %% Common functions
        
        function y = CalcSigm(obj, k, j)
            y  =  1. / (1 + ((obj.alfa+k* obj.sm_alfa) * exp(-(obj.betta +k*obj.sm_bet) * (j /10  - (obj.sd-k*obj.sdsn)))));
        end
        
        function [ k, v]  = Slippage(obj, vBelt,  rotv)
            k=1;
            x = 0;
            if rotv >= 10
                x = 1 - (vBelt)/(rotv' * obj.R );            
            end
            v=x;
            obj.dSlipp( 2:obj.lSlipp) = obj.dSlipp(1:obj.lSlipp-1);
            obj.dSlipp(1) = x;
            
            % I - Режим формирования массива dSlipp  
            if obj.dSlipp(obj.lSlipp)==0
                return;
            end

            sr = sum(obj.dSlipp)/length(obj.dSlipp);
            std4 = std(obj.dSlipp)*obj.kStd;
            % II - Режим ind == 1
            if obj.ind==1
                if obj.dSlipp(1)>(sr + std4)   
                    obj.ind = min(obj.ind+1, 6);
                    k = obj.ind;
                    return;
                end            
                if obj.dSlipp(1)<(sr - std4)   
                    obj.ind=max(obj.ind-1, 1);
                    k = obj.ind;
                    return;
                end
                return;
            end
            % III - Режим ind > 1
            if (obj.dSlipp(1)>(sr + std4)) & (obj.dSlipp(1)>obj.dSlipp(2))
                    obj.ind=min(obj.ind+1, 6);
                    k = obj.ind;
                    return;
                end
                if (obj.dSlipp(1)<(sr - std4)) & (obj.dSlipp(1)<obj.dSlipp(2))
                    obj.ind=max(obj.ind-1, 1);
                    k = obj.ind;
                    return
                end
                k = obj.ind;
                obj.dSlipp(1)=obj.dSlipp(2);        
        end
        
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
        end

        function [y, k, v, ye, yinver ]= stepImpl(obj, signal,  vBelt,  rotv)  % , ss
            [k, v] = Slippage(obj, vBelt,  rotv);
            y = obj.d(obj.ind, max(min(round(signal), 100), 1))
            ye =min( obj.alfaExp * y +obj.alfa1 *  obj.Y0, 1);  % без этой строчки может бать отрицательный момент - торможение
            obj.Y0 = ye;
            yinver=1-ye;
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
            obj.dSlipp(:)=0;
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

        %% Advanced functions
        function validateInputsImpl(obj, signal,  vBelt,  rotv)     % , ss
            % Validate inputs to the step method at initialization
        end

        function validatePropertiesImpl(obj)
            % Validate related or interdependent property values
        end

        function ds = getDiscreteStateImpl(obj)
            % Return structure of properties with DiscreteState attribute
            ds = struct([]);
        end

        function processTunedPropertiesImpl(obj)
            % Perform calculations if tunable properties change while
            % system is running
        end

        function flag = isInputSizeLockedImpl(obj,index)
            % Return true if input size is not allowed to change while
            % system is running
            flag = true;
        end

        function flag = isInactivePropertyImpl(obj,prop)
            % Return false if property is visible based on object 
            % configuration, for the command line and System block dialog
            flag = false;
        end
    end
end
