
from .PlotGraphs import *
import copy
import numpy as np


class Sigmoid:
    def __init__(self, npoint=100):
        self.ts =np.array([round(x) for x in np.linspace(0.0, 100.0, npoint+1, True)])
#        self.tsls=[round(x,1) for x in self.ts]
        self.ind_slip=0
        self.Inicial()

    def Set(self, alfa=1, beta=1, sd=5):
        return 1. / (1 + alfa * np.exp(-beta * (self.ts/10 - sd)))

    def SetS(self, n, alfa=1, beta=1, sd=5):
        return self.Set(alfa, beta, sd), f" {n}: sig - {alfa}, - {beta}, - {sd}"

    def IncSlip(self):
        self.ind_slip += 1
        self.ind_slip=min(5, self.ind_slip)

    def DecrementSlip(self):
        self.ind_slip -= 1
        self.ind_slip=max(0, self.ind_slip)

    def ResetSlip(self):
        self.ind_slip = 0

    def GetSigmoidDan(self, t):
        return self.sig[self.ind_slip][min(int( round(t)), 100 )]

    def Inicial(self):
        sd, sdsn= 6, 0.25
        betta, sm_bet = 0.6, 0.3
        alfa, sm_alfa = 1.0, 0.3
        dan = {
            0: (self.SetS(0, alfa + 0 * sm_alfa, betta + 0 * sm_bet, sd - 0 * sdsn)),
            1: (self.SetS(0, alfa + 1 * sm_alfa, betta + 1 * sm_bet, sd - 1 * sdsn)),
            2: (self.SetS(0, alfa + 2 * sm_alfa, betta + 2 * sm_bet, sd - 2 * sdsn)),
            3: (self.SetS(0, alfa + 3 * sm_alfa, betta + 3 * sm_bet, sd - 3 * sdsn)),
            4: (self.SetS(0, alfa + 4 * sm_alfa, betta + 4 * sm_bet, sd - 4 * sdsn)),
            5: (self.SetS(0, alfa + 5 * sm_alfa, betta + 5 * sm_bet, sd - 5 * sdsn)),
        }

        self.d =  copy.deepcopy(dan)
        for i in range(len( self.d)-2, -1, -1):
            print(f" ----> {i}  ")
            _count = len(self.d[i+1][0][self.d[i][0] > self.d[i+1][0]])
            self.d[i][0][:_count] = self.d[i+1][0][:_count]
            self.d[i] = (copy.deepcopy(self.d[i][0]), self.d[i][1])

        self.sig = {}
        for key, value in self.d.items():
            print(f" ----> формируем sig   {key}  ")
            self.sig[key] = value[0]

    def Test1(self):
        _plot = PlotGraph()
        _plot.OnePlot(self.Set(), "sigmoid0")
        plt.show()

    def Test2(self):
        self.Inicial()
        #        _plot = PlotGraph()  dan={0:(self.ts, , "sig0"),  1:(self.ts, , "sig1")}

        # plt.figure()
        # plt.plot(self.ts, self.dan[0][0], self.ts, self.dan[1][0], self.ts, self.dan[2][0]
        #          , self.ts, self.dan[3][0] , self.ts, self.dan[4][0], self.ts, self.dan[5][0])
        # plt.grid()
        # plt.legend([self.dan[0][1], self.dan[1][1], self.dan[2][1]
        #                , self.dan[3][1], self.dan[4][1], self.dan[5][1]])

        plt.figure()
        plt.plot(self.ts, self.d[0][0]
                 , self.ts, self.d[1][0]
                 , self.ts, self.d[2][0]
                 , self.ts, self.d[3][0]
                 , self.ts, self.d[4][0]
                 , self.ts, self.d[5][0]
)
        plt.grid()
        plt.legend([self.d[0][1]
                       , self.d[1][1]
                       , self.d[2][1]
                       , self.d[3][1]
                       , self.d[4][1]
                       , self.d[5][1]
                    ])

        plt.show()


'''
full_name = lambda first, last: f'Full name: {first.title()} {last.title()}'
>>> full_name('guido', 'van rossum')
'Full name: Guido Van Rossum'


x= linspace(0,10,101);
fx1 = 1./(1+exp(-0.8*(x-5)));
fx2 = 1./(1+1.25*exp(-1.0*(x-4.75)));
fx3 = 1./(1+1.5*exp(-1.2*(x-4.5)));
fx4 = 1./(1+1.75*exp(-1.6*(x-4.25)));
fx5 = 1./(1+2*exp(-1.8*(x-4.0)));
fx6 = 1./(1+2.2*exp(-2.2*(x-3.75)));
plot(x,fx1, x,fx2,x,fx3,x,fx4,x,fx5,x,fx6)
legend()
fxs1(1, :)=1-1./(1+exp(-1*(x-5)));
fxs1(2, :)=1-1./(1+exp(-1*(x-4)));
fxs1(3, :)=1-1./(1+exp(-1*(x-3)));
fxs1(4, :)=1-1./(1+exp(-1*(x-2)));
fxs1(5, :)=1-1./(1+exp(-1*(x-1)));
plot(x,fxs1)
legend()

ff(1,:)=fx6;
f00=fx5(fx5<fx6);
count = length(f00)
f01=fx5;
f01(count,:)=fx6(:count);
ff(2,:)=f0;
plot(x,ff)
legend()
 



'''
