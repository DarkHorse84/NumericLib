#ax''+bx'+cx+d=0
function [x, dx_dt, t] = secondOrder(x, dx_dt ,a ,b ,c ,d ,T ,delT , taylorOrder)
  A = [[0,1];[-c/a,-b/a]];
  B=[0;-d/a];
  val = [x;dx_dt];
  [nextval, tt] = interateOde(val , A, B ,T, delT, taylorOrder);
  x = nextval(1);
  dx_dt = nextval(2);
  t = tt;
endfunction