%%

close all;
clear all;
clc;

%%import data

data = csvread('C:\Users\gedan\Documents\Algoritmos\algoritmos2.2\algoritimos_ordenacao\data.csv',1,0);

Tamanho=data(:,1);
ordenacao(:,1) = data(:,2);
ordenacao(:,2) = data(:,5);
ordenacao(:,3) = data(:,8);
jaordenado(:,1) = data(:,3);
jaordenado(:,2) = data(:,6);
jaordenado(:,3) = data(:,9);
decrescente(:,1) = data(:,4);
decrescente(:,2) = data(:,7);
decrescente(:,3) = data(:,10);

clear data;

%%graficos

plot(Tamanho,ordenacao,'LineWidth',2);
legend('Buble_sort','Merge_Sort','QuickSort');
grid on;
title('Tempo de Ordenacao');
ylabel('Tempo[s]');
xlabel('Tamanho Vetor');

figure;
plot(Tamanho,jaordenado,'LineWidth',2);
legend('Buble_sort','Merge_Sort','QuickSort');
grid on;
title('Tempo ja Ordenacao');
ylabel('Tempo[s]');
xlabel('Tamanho Vetor');

figure;
plot(Tamanho,decrescente,'LineWidth',2);
legend('Buble_sort','Merge_Sort','QuickSort');
grid on;
title('Tempo de decresnte');
ylabel('Tempo[s]');
xlabel('Tamanho do vetor');
