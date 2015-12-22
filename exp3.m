%MATLAB CODE
%GIbb's phenomenon of the Rectangular pulse train
t=-1.1:0.001:1.1;
T=1;
tau=0.2;
a0=tau/T;
n=50;%Number of Harmonic components
ft=a0;
for i=1:n,
    ft=ft+(2/T)*tau*sinc(i*tau/T)*cos(2*pi*i*t/T);
end
plot(t,ft);%plot the sum of fourier Components
xlabel('Time....');
ylabel('Amplitude');
title('Gibbs Phenomenon for n=50');
hold on;
t=[-1.1 -1.1 -.9 -0.9 -0.5 -0.1 -0.1 0.1 0.1 0.5 0.9 0.9 1.1 1.1];
ft=[0 1 1 0 0 0 1 1 0 0 0 1 1 0];
plot(t,ft,'r');%plot the orginal saw tooth wave
hold off;
grid on
