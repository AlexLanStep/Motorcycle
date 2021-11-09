classdef WolchSim < matlab.System & handle
    % Untitled Add summary here
    %
    % NOTE: When renaming the class name Untitled, the file name
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

    properties(DiscreteState)

    end

    % Pre-computed constants
    properties(Access = private)
        nfft, 
        ind=0,
        mD,
%        mask = [0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
        mask = [0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0]
        
    end

    methods
        % Constructor
        function obj = WolchSim()
%        function obj = WolchSim(varargin)
            % Support name-value pair arguments when constructing object
%            setProperties(obj,nargin,varargin{:})
            obj.nfft = 64;
            obj.mD =  zeros(1, obj.nfft);
           
        end
    end

    methods(Access = protected)
        %% Common functions
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
        end

        function y = stepImpl(obj, u, norm)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
            obj.mD(1:obj.nfft-1) = obj.mD(2:obj.nfft);
            obj.mD(obj.nfft) = u;
            y0 = abs(fwht(obj.mD));
            count_mask = length(obj.mask);
            y1 = y0(1: count_mask)';
            y = double(obj.mask*y1);
            y=y/norm;
            y=min(y,1);
%            obj.ind = obj.ind+1;
%            kk=obj.ind
%            ff=y
             
% xxx1 = xxx0(n: n+64)
% y = abs(fwht(xxx1))
% y1=y(1:65)'
% y2=mnogMatr*y1             
            
%             y = abs(fwht(obj.mD));
%             y = obj.mask * y0';            
%             y = u*10;
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

%         function out = getOutputSizeImpl(obj)
%             % Return size for each output port
%             out = [1 obj.nfft];
% 
%             % Example: inherit size from first input port
%             % out = propagatedInputSize(obj,1);
%         end
% 
%         function out = getOutputDataTypeImpl(obj)
%             % Return data type for each output port
%             out = "double";
% 
%             % Example: inherit data type from first input port
%             % out = propagatedInputDataType(obj,1);
%         end
% 
%         function out = isOutputComplexImpl(obj)
%             % Return true for each output port with complex data
%             out = true;
% 
%             % Example: inherit complexity from first input port
%             % out = propagatedInputComplexity(obj,1);
%         end

        function loadObjectImpl(obj,s,wasLocked)
            % Set properties in object obj to values in structure s

            % Set private and protected properties
            % obj.myproperty = s.myproperty; 

            % Set public properties and states
            loadObjectImpl@matlab.System(obj,s,wasLocked);
        end

        %% Advanced functions
        function validateInputsImpl(obj,u)
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
            % Perform actions when tunable properties change
            % between calls to the System object
        end

        function flag = isInputSizeMutableImpl(obj,index)
            % Return false if input size cannot change
            % between calls to the System object
            flag = false;
        end

        function flag = isInactivePropertyImpl(obj,prop)
            % Return false if property is visible based on object 
            % configuration, for the command line and System block dialog
            flag = false;
        end
    end
end
