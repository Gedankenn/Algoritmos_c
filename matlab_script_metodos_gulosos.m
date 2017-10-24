%% 

close all;
clear all;
clc;
%% import
data = csvread('C:\Users\gedan\OneDrive\Documentos\Algoritmos\data.csv',1,0);

lucro(:,1) = data(:,3);
lucro(:,2) = data(:,6);
lucro(:,3) = data(:,9);
peso(:,1) = data(:,2);
peso(:,2) = data(:,5);
peso(:,3) = data(:,8);

clear data;

%% graficos
plot(lucro,peso,'LineWidth',2);
legend('lucro','peso','lucro/peso');
grid on;
title('algoritimos gulsos(mochila)');
ylabel('peso');
xlabel('lucro');

%% intepreta dados


