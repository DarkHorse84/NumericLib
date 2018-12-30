#1*x''+0*x'+kx+0=0
clear;
delT = 0.001;
T=[0];

X3=[1];
dX3_dt=[0];

XG=[1];
dXG_dt=[0];
endTime =20;
k=1;
while (T(length(T))<endTime)
  
  [x, dx_dt, t] = secondOrder(X3(length(X3)), dX3_dt(length(dX3_dt)), 1,0 , k,0 , T(length(T)), delT, 2);
  X3 = [X3, x];
  dX3_dt = [dX3_dt, dx_dt];
  
  [nextVal, t] = genericOde([XG(length(XG)); dXG_dt(length(dXG_dt))] ,[0 k 0 1] ,T(length(T)), delT, 2);
  XG = [XG, nextVal(1)];
  t
  dXG_dt = [dXG_dt, nextVal(2)];
  T = [T,t];
endwhile

plot(T,X3);
hold on;
plot(T,dX3_dt);
plot(T,XG);
plot(T,dXG_dt);