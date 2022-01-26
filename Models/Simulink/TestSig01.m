classdef TestSig01 < matlab.System
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
         M1 = zeros(151, 1)
         M1count = 151 

        kxx=0
        u_sig_k=0.0
        ind = struct('sig', 0, 'nCount', 0, 'i', 0)
        y_old=0.0, 
        nEma=0, alfa_ema=0.0, alfa_ema1=0.0
    end

    % Pre-computed constants
    properties(Access = private)

    end

    methods
        % Constructor
        function obj = TestSig01(varargin)
            % Support name-value pair arguments when constructing object
            %setProperties(obj,nargin,varargin{:})
        end
    end

    methods(Access = protected)
%    methods(Access = public)
        %% Common functions  Инициализация переменных
        function setupImpl(obj)
            obj.u_sig_k=0.0;
            obj.y_old=0.0;
            obj.nEma=250;
            obj.alfa_ema=2/(obj.nEma+1);
            obj.alfa_ema1 = 1-obj.alfa_ema;
        end
        
        function y = stepImpl(obj,u)
            y =  obj.ind.i;
            if u==0  
                return
            end
            
            obj.ind.i=obj.ind.i + 1;
            y=obj.ind.i;
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




