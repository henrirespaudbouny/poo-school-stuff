// TF de x
function X1 = tf(f,q)
    f0= 30
    X1 = 1/2*((q*(q^2+4*(%pi^2)*(f-f0).^2).^(-1))+(q*(q^2+4*(%pi^2)*(f+f0).^2).^(-1)))
endfunction

//q = 5
f = [-100:1:100]

//x = tf(f,q)
//subplot (211)
//plot(f,x)

q = 15
//x2 = tf(f,q)
//subplot (212)
//plot(f,x2)


// Q3


function X2 = SE(f,q,Te)
    somme = 0
    for n = -100:100
       somme = somme + tf((f-n*Te.^(-1)),q)
    end
    X2 = 1*(Te.^(-1)) * somme
endfunction

//Te = 1*120.^(-1) 
//f = [-1*(2*Te).^(-1):1:1*(2*Te).^(-1)]
//x = SE(f,q,Te)
//subplot (311)
//plot(f,x)
//
//Te = 1*70.^(-1) 
//f = [-1*(2*Te).^(-1):1:1*(2*Te).^(-1)]
//x = SE(f,q,Te)
//subplot (312)
//plot(f,x)
//
//Te = 1*30.^(-1) 
//f = [-1*(2*Te).^(-1):1:1*(2*Te).^(-1)]
//x = SE(f,q,Te)
//subplot (313)
//plot(f,x)


// Q4
Te = 1*70.^(-1) 
f = [-1*(Te).^(-1):1:1*(Te).^(-1)]

// Filtre passe-bas
function X3 = PB()
    passeBas = tf(f,q)
    passeBas = find(passeBas<35)
    passeBas = find(passeBas>-35)
    X3 = passeBas
endfunction

//x ˆ (f )
x = tf(f,q)
subplot (211)
plot(f,x)

//T e X ˆ e (f ).
x = (1*70.^(-1))*SE(f,q,Te)
subplot (211)
plot(f,x)

x = PB()
subplot (212)
plot(f,x)
