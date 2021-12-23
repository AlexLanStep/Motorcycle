classdef CMoment < matlab.System
    % Untitled2 Add summary here
    %
    % NOTE: When renaming the class name Untitled2, the file name
    % and constructor name must be updated to use the class name.
    %
    % This template includes most, but not all, possible properties,
    % attributes, and methods that you can implement for a System object.

    % Public, tunable properties
    properties

    end

    % Public, non-tunable properties
    properties(Nontunable)

    end

    properties(Access  = private)
        X =   [600.0, 1000.0, 1250.0, 1500.0, 1750.0, 2000.0, 2250.0, 2500.0, 2750.0, 3000.0, 3500.0, 4000.0, 4500.0, 5000.0, 57500.0, 65000.0 ]
        Y =   [0.0, 5.0049, 9.9976, 15.0024]
        Z =  [0,     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0;
                35.9,  28.5,   23.0,   18.1,   16.2,   14.2,   10.7,   9.7,    9.1,    9.8,    10.9,   11.8,   13.40,  16.3,   19.0,   20.0;
                80.20,  68.6,    58.5,   53.3,   47.0,   45.0,   42.1,   39.8,   38.0,   36.7,   38.0,   35.3,   36.4,   38.1,   43.0,   42.0 ;
                123.20, 105.5,   95.1,   87.2,   81.0,   75.9,   71.9,   68.6,   64.8,   64.6,   64.4,   62.4,   62.3,   63.0,   65.0,   64.2 ]        
            
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
        end
    end

    methods(Access = protected)
        %% Common functions
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            
        end

        function out1 = stepImpl(obj, dx, dy)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
            out1 = interp2(obj.X, obj.Y, obj.Z, dx, dy, 'spline')  ;
            n=10
            step=0.01
            x = [0:step:(n-1)*step]
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
        function validateInputsImpl(obj,u, v)
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
