classdef WhDebagSimul <   handle
    
    %UNTITLED Summary of this class goes here
    %   Detailed explanation goes here
    
    properties(Access  = private)
        nWht = 64;
        n_section = 6;
        nSectionPlus=7;
        msp = zeros(64, 7);
        
    end
    
    methods
         function obj =  WhDebagSimul()
%             disp(" classdef WhDebagSimul  ")
         end
         
         function [Y, Ynorm] = Step(obj, u, norm)
            obj.msp(2:obj.nWht, :) = obj.msp(1:obj.nWht-1, :);
            obj.msp(1,1) = u;
             
             Y = 0;
             Ynorm = 0;
         end
    end
    
end

