function poankreDelone(a, e, i, lambda, w, tita, mu)
i = i * pi/180;
lambda = lambda * pi/180;
w = w * pi/180;
tita = tita * pi/180;

t0 = lambda - w;
t = 261/365.25 * 2 * pi;
gamma = sqrt(1 + mu);
n = sqrt((1+mu)/a^3);

%Delone( L, G, ThetaBig, l, g, tita)
L = mu * sqrt(gamma) * sqrt(a);
G = L*sqrt(1-e*e);
ThetaBig = G * cos(i);
l = n*t + t0;
g = w - tita;

d = {'Delone el:', L, G, ThetaBig, l, g, tita};

%Poincare1(L, L-G, G-ThetaBig, lambda, w, tita)
p1 = {'Poincare 1k:', L, L-G, G-ThetaBig, lambda, w, tita };

%Poincare2(L, ksi, p, lambda, eta, q)
ksi = sqrt(2*(L-G)) * cos(g+tita);
p = sqrt(2*(G-ThetaBig)) * cos(tita);
eta = -sqrt(2*(L-G)) * sin(g+tita);
q = -sqrt(2*(G-ThetaBig)) * sin(tita);

p2 = {'Poincare 2k:', L, ksi, p, lambda, eta, q };

disp(d);
disp(p1);
disp(p2);


end