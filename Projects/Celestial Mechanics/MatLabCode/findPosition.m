function findPosition (a, e, i, L, w, tita, mu)
i = i * pi/180;
L = L * pi/180;
w = w * pi/180;
tita = tita * pi/180;

g = w - tita;
t = 261/365.25 * 2 * pi;
l_2000 = L - w;
n = sqrt((1+mu)/a^3);
l = n * t + l_2000;

u = l + e*sin(l + e*sin(l + e*sin(l)));

A = [ cos(tita) -sin(tita) 0;
      sin(tita) cos(tita)  0;
      0         0          1;
];
B = [ 1 0      0;
      0 cos(i) -sin(i);
      0 sin(i) cos(i);
    ];
C = [ cos(g) -sin(g) 0;
      sin(g) cos(g)  0;
      0      0       1;
    ];
Q = A*B*C;
V = Q*a*n/(1-e*cos(u))*[-sin(u);sqrt(1-e^2)*cos(u);0];
D = [ a*(cos(u) - e);
      a*(sqrt(1-e^2)*sin(u));
      0;
     ];
 coordinates = Q*D;
 disp('Coordinates');
 disp(coordinates);
 disp(norm(coordinates));
 disp('Speed:');
 disp(V);
 disp(norm(V));
end