K = nfinit(x^3 + 5);
S = [1,2,3,x,x+1,x+2,x^2,x^2+3,[1,2,3]~,[3,4,5]~,[1,0,1]~,x^2 + 5];
sfact(K,S,2)
sfact(K,S,4)
sfact(K,S,8)
sfact(K,S,#S-1)