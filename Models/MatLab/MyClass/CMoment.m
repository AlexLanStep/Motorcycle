classdef CMoment <  matlab.System
    %  handle &  
    % Public, tunable properties
    properties

    end

    % Public, non-tunable properties
    properties(Nontunable)

    end

    properties(Access  = private)
        NCount, nm;
        m = zeros(1, 200);              
        x0,  xsum, x2sum, x_sr, x_0, x_01, x_001, xsum2, z0, z01, z002;
    end
    properties(DiscreteState)
    end

    % Pre-computed constants
    properties(Access = private)
    end

    methods
        % Constructor
        function obj = CMoment(varargin)
            % Support name-value pair arguments when constructing object
            setProperties(obj,nargin,varargin{:})
            obj.NCount = 200;
            obj.nm = -1;
        end
    end

    methods(Access = protected)
        %% Common functions
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
        end

        function outMoment  = stepImpl(obj, moment, npoint, err)
            n = max(min(npoint, 200), 6);
            obj.nm = n;
            obj.m(1, 1:obj.NCount-1) = obj.m(1,  2:obj.NCount);
            if err==0
                obj.m(1, obj.NCount) = double(moment);    
            else
                obj.m(1, obj.NCount) = double(obj.m(1, obj.NCount-1));    
            end
            
%            kodError = length(obj.x0)
            
%            if (obj.nm ~= n) | (kodError==0)
                obj.nm = n;
                obj.x0 = [0:n-1];
                obj.xsum = sum(obj.x0(1,1:n));
                obj.x2sum = sum(obj.x0.^2);
                obj.x_sr = obj.xsum / n;
                obj.x_0 = obj.x0 -obj.x_sr;
                dx = obj.x_0.*obj.x_0;
                obj.x_01 = sum(obj.x_0.^2);
                obj.x_001 = 1/obj.x_01;
                obj.xsum2 = obj.xsum * obj.xsum;
                obj.z0 = obj.x2sum / obj.xsum2;
                obj.z01 = 1 / (1 - (obj.z0 * n));
                obj.z002 = 1 / obj.xsum;
%            end

            
            yy = obj.m(1,  obj.NCount- obj.nm +1: obj.NCount);
            ysum = sum(yy);
            y2sum = sum(yy.^2);
            xy = obj.x0.*yy;
            xysum = sum(xy);
            y_sr = ysum / n;
            y_0 = yy-y_sr;
            su = sum(obj.x_0.* y_0);
            b = su*obj.x_001;
            z1 = xysum*obj.z002;
            betta = (z1-obj.z0*ysum)*obj.z01;
            alfa = (ysum - betta * n) * obj.z002;
            outMoment = alfa*(n-round(n/3))+betta;
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

        %% Advanced functions
        function validateInputsImpl(obj, moment, npoint, err)
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
