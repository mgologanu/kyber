
p = 7681;

cnt = 0;
cnt2 = 0;
%% Montgomery using only 32 bit integers

%%p = 3329;

p = 7681;

R = 2^16;

p_prim = 7679;

R_inv = 900;  %%inverse of R mod p, needed for checking the results

N = p;         %%13 bits
Np = p_prim;   %%13 bits


%%Exhaustive check

for a = 0:p-1
  for b = 0:p-1

    T = a*b;  %% 26 bits

    m = mod(T,R);  %% 16 bits
    m = m * Np;    %% 29 bits
    m = mod(m, R);  %% 16 bits

    t = T+m*N;     %% 26+29 bits, max 30 bits
    
    r1 = floor(t/R); 

    r2 = r1 - p;
    
    if (r2<0)
      r = r1;
    else
      cnt = cnt + 1;
      r = r2;
    end
      
    if (r-mod(T*R_inv,p) ~= 0)
      disp(a);
      disp(b);
      disp(r);
      disp(mod(a*b,p));
      disp("\n");
    end
      
    
  end
end
