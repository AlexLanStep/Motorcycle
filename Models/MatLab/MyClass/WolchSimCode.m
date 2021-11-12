%classdef WolchSimCode < handle & matlab.System & matlab.system.mixin.Propagates
classdef WolchSimCode < handle & matlab.System  %& matlab.system.mixin.Propagates
%    properties
%    end
    properties(SetAccess  = public)
    end
%   properties(SetAccess  = private)
   properties(Access  = private)
        nWht = 64;
		n_section = 6;
        nSectionPlus=7;
        msp = zeros(64, 7);
        y0_=0.0;
    end

    % Public, non-tunable properties
    properties(Nontunable)

    end

    properties(DiscreteState)

    end

    % Pre-computed constants
    properties(Access = private)

    end

    methods
        % Constructor
        function obj = WolchSimCode(varargin)
            % Support name-value pair arguments when constructing object
            setProperties(obj,nargin,varargin{:})
            
        end
    end

    methods(Access = protected)
        %% Common functions
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
        end

        function [y0, y] = stepImpl(obj, u, norm)
            obj.msp(2:obj.nWht, :) = obj.msp(1:obj.nWht-1, :);
            obj.msp(1,1) = u;
            
            k = 2;
            for i = 2: obj.n_section
                sm_k = obj.nWht / k;

                 for k0=1 : k
                     if mod(k0, 2) ==0
                         iii1=i
                         iii=k0
                     else
                         jjjj1=i
                         jjjj=k0
                     end
                 end
                
                
%                 
%                 for k0=0 : k-1
%                     if mod(k0, 2) ==0
%                         for i0=sm_k*k0 : (sm_k*(k0+1)-1)
%                             obj.msp(i0+1, i+1) = obj.msp(i0,  i-1) ; % - obj.msp(i0+ sm_k, i - 1);
%                         end
%                     else
%                         for i0=(sm_k*k0 : sm_k*(k0+1)-1)
%                             obj.msp(i0+1, i+1) = obj.msp(i0,  i-1) ; % + obj.msp(i0- sm_k, i - 1);
%                         end
%                     end
%                 end
                    
                k = k * 2;
            end
%             
%             for i=1:obj.nWht
%                 if mod(i, 2) ==0
%                     obj.msp(i, obj.nSectionPlus) =	obj.msp(i, obj.nSectionPlus - 1)  - obj.msp(i + 1, obj.nSectionPlus - 1);
%                 else
%                     obj.msp(i, obj.nSectionPlus) =	obj.msp(i, obj.nSectionPlus - 1) + obj.msp(i - 1, obj.nSectionPlus - 1);
%                 end
%             end
% 
%             v = 0.0;
%             for i=1:(obj.nWht/2-1)
%                 i0 = i * 2;
% 				v =v +	abs(obj.msp(i0 + 1, obj.nSectionPlus)) + abs(obj.msp(i0 + 2, obj.nSectionPlus));
%             end
%            y0 = v;
            y0=0;
            y = u*norm;
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

        function [out,out2] = isOutputFixedSizeImpl(obj)
            % Return true for each output port with fixed size
            out = true;
            out2 = true;

            % Example: inherit fixed-size status from first input port
            % out = propagatedInputFixedSize(obj,1);
        end

        function loadObjectImpl(obj,s,wasLocked)
            % Set properties in object obj to values in structure s

            % Set private and protected properties
            % obj.myproperty = s.myproperty; 

            % Set public properties and states
            loadObjectImpl@matlab.System(obj,s,wasLocked);
        end

        %% Advanced functions
        function validateInputsImpl(obj,u, norm)
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
