%% 

close all;
clear all;
clc;
%%

data =csvread('C:\Users\gedan\OneDrive\Documentos\Algoritmos\conversa_carol.csv',1,0);

hora=data(1,:);
mes1(1,:)=data(2,:);
mes1(2,:)=data(3,:);




%%

plot(hora,mes1,'LineWidth',1);
legend('mes 5','mes 6');
grid on;
title('conversas');
ylabel('msg');
xlabel('hora');
