classdef ModulSigmoid1 < handle & matlab.System
    % Untitled2 Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

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
        
    end

    properties(DiscreteState)

    end

    % Pre-computed constants
    properties(Access = private)
        d = zeros(6, 101);
        ind = 0;
        dSlipp = [0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0];
        lSlipp = 0;
    end

        methods
        % Constructor
        function obj = ModulSigmoid(varargin)
            % Support name-value pair arguments when constructing object
            setProperties(obj,nargin,varargin{:})

            for i=1:6
                for j=1:101
                    obj.d(i, j)= CalcSigm(obj, i-1,   j-1);       
                end
            end            
            
            [i0, j0]  = size(obj.d)
            for k=i0-1:-1:1
                disp(k)
                count = length(obj.d(k, obj.d(k,:)  >  obj.d(k+1, :)))
                obj.d(k,1:count) = obj.d(k+1,1:count);
            end
            
            obj.lSlipp = length(obj.dSlipp);
        end
    end

    methods(Access = protected)
         function setupImpl(obj)
             % Perform one-time calculations, such as computing constants
         end
        
        function y = CalcSigm(obj, k, j)
            y  =  1. / (1 + ((obj.alfa+k* obj.sm_alfa) * exp(-(obj.betta +k*obj.sm_bet) * (j /10  - (obj.sd-k*obj.sdsn)))));
        end
        
        function obj  = Slippage(obj, vBelt,  rotv)
            R =  obj.Rwheel  *  obj.Transfer;
            
            if rotv <= 10
                x = 0;
            else
                x = 1 - (vBelt)/(rotv'*R );            
            end
            
            obj.dSlipp( 2:obj.lSlipp) = obj.dSlipp(1:obj.lSlipp-1);
            obj.dSlipp(1) = x;
            
             if obj.dSlipp(obj.lSlipp) ~= 0
                 obj.ind=0;
             else
                 sr = sum(obj.dSlipp)/obj.lSlipp;
                 sd = std(obj.dSlipp);
                 if obj.dSlipp(1)>(sr + sd)
                     obj.ind = min(obj.ind+1,  6);
                 elseif obj.dSlipp(1)<(sr - sd)
                     obj.ind = max(obj.ind-1, 0);
                 else
                     obj.ind = obj.ind;
                 end
                 if x < obj.Kreset  % если значения x меньше 
                     obj.ind = 0;
                 end
             end
        end
        
        function y = stepImpl(obj, signal,  vBelt,  rotv)
%            Slippage(obj, vBelt,  rotv)
            i = min(round(signal), 100)
            y = obj.d(obj.ind, i)
%                y=min(round(signal), 100);
%                y=signal/50;
        end

        function resetImpl(obj)
             obj.ind = 0;
            % Initialize / reset discrete-state properties
        end
    end
end
