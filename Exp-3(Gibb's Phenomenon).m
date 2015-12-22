%MATLAB CODE
%Gibb's phenomenon of saw tooth wave

t=-0.5:0.001:1.5;
T=1;
C0=0.5;
n=10; %Number of Harmonic components
ft=C0;
for i=1:n,
    ft=ft-2/(2*pi*i)*sin(2*pi*i*t/T);
end
plot(t,ft); %plot the sum of fourier Components
xlabel('Time....');
ylabel('Amplitude');
title('Gibbs Phenomenon for n=10');
hold on;
t=[-0.5 0 0 1 1 1.5];
ft=[0.5 1 0 1 0 0.5];
plot(t,ft,'r'); %plot the orginal saw tooth wave
hold off;

grid on
