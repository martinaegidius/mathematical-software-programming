
tiledlayout('flow');
nexttile
n = linspace(10,40,100);
time = n.^2;
semilogy(n,time)

nexttile 
time = log(n);
semilogy(n,time);

nexttile
time = 2.^n;
semilogy(n,time)

nexttile
time = n;
%time=ones(numel(n),1);
semilogy(n,time)