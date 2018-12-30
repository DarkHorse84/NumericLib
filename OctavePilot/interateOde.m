function [nextval, t] = interateOde(val , A, B ,T, delT, taylorOrder)
  nextval=val;
  curOrder = 0;
  for n=1:taylorOrder
    nextval = nextval+(A^n*val+A^(n-1)*B)*(delT^n)/factorial(n);
  endfor
  t = T+delT;
endfunction
