
p = 7681;

cnt = 0; %% counter for number of cases with r>p needing a subtraction

%% Barrett using only 32 bit integers

%%p = 3329;

p = 7681;

%% Exhaustive check

for a = 0:p-1
  for b = 0:p-1
    bp = floor(b*2^16/p); %% bp  has max 16 bits, as b<p

    ab = a*b;  %% a*b has max 26 bits 

    t = a * bp;   %% t has max 13+16 = 29 bits

    q = floor(t/2^16);  %%q has max 13 bits

    qp = q*p;           %%qp has max 26 bits

    %%Calculate both r and r-p for constant time implementation
    r1 = ab - qp;       

    r2 = r1 - p;

    %% Select the result, comparison to zero is faster
    if (r2<0)
      r = r1;
    else
      cnt = cnt + 1;
      r = r2;
    end

      
    if (r-mod(ab,p) ~= 0)
      disp(a);
      disp(b);
      disp(r);
      disp(mod(a*b,p));
      disp("\n");
    end
      
    
  end
end
