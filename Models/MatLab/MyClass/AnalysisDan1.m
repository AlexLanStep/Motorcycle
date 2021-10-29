classdef AnalysisDan1  <  handle
    properties
%        Dan,   setParamInfo
        setParamInfo, setparam_sp
        Dan LoadDan1 
        MyF MFilter
        plot2021
    end
    
    properties (SetAccess = private)
    end
    
    methods
        function obj =  AnalysisDan1(setpathx, setparaminfo)
            obj.setParamInfo  =  setparaminfo;    
            obj.Dan =  LoadDan1(setpathx.Dir, setpathx.Files);
            obj.MyF = MFilter();
            obj.plot2021 = Plot2021();
        end
        
        function  PlotXYZ(obj, names)
            if exist('names')==0      %  ���
                    names=["XYZ.X",  "XYZ.Y", "XYZ.Z"];                        
            end
            PlotXnames(obj, names);
        end
        
        function  PlotXYZg(obj, names)
            if exist('names')==0    %  ���
                    names=["PitchVel", "RollVel", "YawVel", "YawAcc"];
            end
            PlotXnames(obj, names);
        end
        
        function  Engine(obj, names)
            if exist('names')==0   %  ���
                    names=["Engine.Trq", "Engine.Rotv"];
            end
            PlotXnames(obj, names);
        end

        function  muRoad(obj, names)
            if exist('names') == 0    %  ���
                    names=["muRoad.F", "muRoad.R"];
            end
            PlotXnames(obj, names);
        end

        function  Speed(obj)
            names=["Speed"];
            PlotXnames(obj, names);
        end

        function  vBelt(obj, names)
            if exist('names') == 0    %  ���
                names=["vBelt.F", "vBelt.R"];
            end
            PlotXnames(obj, names);
        end
        
        function  PlotXnames(obj, names)
            plot1 = MyPlot(obj.Dan.Time, obj.Dan.Gets(names), names, obj.setParamInfo) ;                            
            plot1.AllPlot()
        end

        function zOut = Spectrum(obj, names, setparam_sp)
            obj.setparam_sp = setparam_sp;
            zOut = cell(1,1);
            disp("  -- spectrum  from data:")
            T=[];
            TT=obj.Dan.Time;
            for i=1:length(names)
                ss=names(i);
                T = obj.Dan.Get(ss);
                fftx = MyFFT01(TT, T, setparam_sp);             
                [e,z] = fftx.AllFFTe();   
                figure
                mesh(z)                
                title(" spectrum " + obj.setParamInfo.Title + "   "+ ss)
                figure
                plot(e)
                title(" energy " + obj.setParamInfo.Title  + "   "+  ss)
                zOut{i,1}= struct('name',  ss, 'z', z, 'e', e);   
            end
        end
            
        function  z = Proskal(obj)
            % ���� ������� 1-(V/w*R)
            r0 = 25.4*17/1000;
            %V = DanConvert.speed;
            V =  obj.Dan.Get("vBelt.R");           %DanConvert.vBelt.F;
            kp=3;
            %w0=2*pi*f
            vr=r0/kp* obj.Dan.Get("Engine.Rotv");       %DanConvert.Engine.Rotv;
            count = length(obj.Dan.Time);
            vmax = zeros(1, count);
            for i=1:count
                vmax(1,i)  = max(V(i),vr(i));
            end
            z = 1-(V./(vmax));
            obj.myPlotone(z, "���������������")
        end
        
        function z = mU(obj)
            z =obj.Dan.Get("Frc.X")./obj.Dan.Get("Frc.Z");
            obj.myPlotone(z, "mU")
        end
        
        function myPlotone(obj, d, name)
            figure
            plot(d)
            title(name)            
        end
        
        function FiltrSpectrumBasa(obj, time, d, name)
            Tcount = length(time);
            obj.myPlotone(d, name);
            fftx = MyFFT01(time, d, obj.setparam_sp);             
            [e,z] = fftx.AllFFTe();   
            figure
            mesh(z)                
            title(" spectrum " + obj.setParamInfo.Title + "   "+ name)
            figure
            plot(e)
            title(" energy " + obj.setParamInfo.Title  + "   "+  name)
        end
        
        function FiltrSvchChebSpectrum(obj, ticker, titlex)
            %NCount
            d =obj.MyF. FSVCH_Cheb(obj.Dan.Get(ticker));
            obj.myPlotone(d, titlex);
            fftx = MyFFT01(obj.Dan.Time, d, obj.setparam_sp);             
            [e,z] = fftx.AllFFTe();   
            figure
            mesh(z)                
            title(" spectrum " + obj.setParamInfo.Title + "   "+ titlex)
            figure
            plot(e)
            title(" energy " + obj.setParamInfo.Title  + "   "+  titlex)
        end
        
        function PlotSignal2021(obj, nameSignal)
            i=1;
            mm=cell(1,1);
            mm{1,1}=struct('mas', obj.Dan.Get(nameSignal), 'title', nameSignal);
            if nameSignal ~= 'YawAcc'
                nextFiltr =FNChEleps(mm{1,1}.mas)*10;
                mm{2,1}=struct('mas', nextFiltr, 'title', " - filtr "+nameSignal);
                fftx = MyFFT01(obj.Dan.Time, nextFiltr, obj.setparam_sp);             
                i=3;
            else
                fftx = MyFFT01(obj.Dan.Time, mm{1,1}.mas, obj.setparam_sp);             
                i=2;
            end
            [e,z] = fftx.AllFFTe();   
            mm{i,1}=struct('mas', z, 'title', " - spectr "+nameSignal);
            i=i+1;
            mm{i,1}=struct('mas', e', 'title', " - energya spectra "+nameSignal);
            obj.plot2021.PlotVertical(mm);
        end
    end
    
end

