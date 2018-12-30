#coEffs(1)+coEffs(2)x+coEffs(3)x'+coEffs(4)x''...+coEffs(n)x^(n-2)=0 (superscipt means derivative)
function [nextval, t] = genericOde(val ,coEffs ,T, delT, taylorOrder)
  A=eye(length(coEffs)-3);
  A=[zeros(length(coEffs)-3,1) A];
  lastRow=[];
  for i = 2:length(coEffs)-1
    lastRow = [lastRow -coEffs(i)/coEffs(length(coEffs))];
  endfor
  A=[A;lastRow];
  B=zeros(length(coEffs)-3,1);
  B=[B;-coEffs(1)/coEffs(length(coEffs))];
  [nextval, t] = interateOde(val , A, B ,T, delT, taylorOrder);
endfunction
