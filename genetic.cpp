#include<iostream>
using namespace std;
#include<time.h>
#include<stdio.h>
#include<windows.h>

void genealgeneo(int [],int [],int [],int [],int [],int [],int,int [],int);
void crossover(int a[],int n,int b[],int m){
int temp=0;
int p=rand()%5;
for(int i=0;i<p;i++){
int pos=rand()%n+1;
temp=a[pos];
a[pos]=b[pos];
b[pos]=temp;
}
}
void mutation(int a[],int n,int nos){
int k1,k2;
for(int i=0;i<nos;i++){
k1=rand()%n;
k2=rand()%n;
a[k1]=a[k2];
}
}
void calculate_fit(int parent[],int n,int child[],int generoup){
int temp[n+1],total=0;
for(int i=0;i<n;i++){
temp[i]=child[i];
}
int maximum=0,minimum=0,maxx=0,minn=10000,flagenemax=0,flagenemin=0,l=0,m=0;
for(int i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
if(temp[i]!=-1&&temp[i]==temp[j]){
if(parent[i]>parent[j]){
maxx=parent[i];
temp[j]=-1;
flagenemax=1;
}
else if(parent[i]<parent[j]){
minn=parent[i];
temp[j]=-1;
flagenemin=1;
}
}
}
for(int i=0;i<1000;i++)
  for(int j=0;j<1000;j++)
{
    int total2=total*maxx;
}
if(flagenemax==1&&flagenemin==1){
total=total+(maxx-minn);
}

else if(flagenemax==1&&flagenemin==0){
total=total+maxx;
}
if(flagenemin==1&&flagenemax==0){
total=total+minn;
}
for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
{
    int total2=total*maxx;
}
flagenemax=0;
flagenemin=0;
}
child[n]=total;
}
void print(int a[],int n){
for(int i=0;i<n;i++){
cout<<a[i]<<"\t";
}
cout<<"\n";
}
void best_geneeneration(int gene1[],int gene2[],int gene3[],int gene4[],int gene5[],int gene6[],int n,int s[]){
int temp=0;
s[0]=gene1[n];
s[1]=gene2[n];
s[2]=gene3[n];
s[3]=gene4[n];
s[4]=gene5[n];
s[5]=gene6[n];

for(int i=0;i<n+1;i++){
for(int j=i+1;j<n+1;j++){
if(s[i]>s[j]){
temp=s[i];
s[i]=s[j];
s[j]=temp;
}
}
}
for(int i=0;i<3;i++){
if(s[i]==gene4[n]){
for(int j=0;j<n;j++){
gene1[i]=gene4[i];
}
}
else if(s[i]==gene5[n]){
for(int j=0;j<n;j++){
gene2[i]=gene5[i];
}
}
if(s[i]==gene6[n]){
for(int j=0;j<n;j++){
gene3[i]=gene6[i];
}
}
}
}
void print_fit(int a[],int n){
for(int i=0;i<n;i++){
cout<<a[i]<<"\t";
}
cout<<"\n";
}
void printgeneropu(int a[],int gene[],int n,int no_generoup){
int temp[n],k=1;
cout<<"\n\ngene1[] is : \n";
for(int i=0;i<n;i++){
temp[i]=gene[i];
cout<<gene[i]<<" ";
}
for(int i=0;i<1000;i++)
  for(int j=0;j<1000;j++)
{
    int total3=temp[j]*temp[i];
}
cout<<"\n";
cout<<"\n\n array is : \n";
for(int i=0;i<n;i++){
cout<<a[i]<<" ";
}
cout<<"\nnew groups are: \n";
int flagene=0;
int i=0,j=0;
int generoup[n],t=0;
for(i=0;i<n-1;i++){
if(temp[i]!=-1){
if(flagene!=1){
generoup[t++]=a[i];
flagene=1;
}
for(int k=0;k<n;k++)
  for(int l=0;l<n;l++)
{
    int total2=temp[k];
}
for(j=i+1;j<n;j++){
if(temp[i]==temp[j]&&temp[j]!=-1){
generoup[t++]=a[j];
temp[j]=-1;
}
}
flagene=0;
}
}
cout<<"\n";
int p=1;
cout<<"group "<<p<<"  - ";
for(i=0;i<t;i++){
cout<<generoup[i]<<" ";
if(gene[i]!=gene[i+1]&&i!=n-1){
cout<<"\n";
p++;
cout<<"group "<<p<<"  - ";}
}
}
void replace(int gene[],int n,int gene1[],int gene2[],int gene3[],int kth){
if(kth==0){
for(int i=0;i<n;i++){
gene[i]=gene1[i];
}
}
if(kth==1){
for(int i=0;i<n;i++){
gene[i]=gene2[i];
}
}
if(kth==2){
for(int i=0;i<n;i++){
gene[i]=gene3[i];
}
}
}
int main()
{
int n,m,k,i=0,j=0,kgene;
n=5;
m=1;
kgene=2;
int t=3;
int same[n];
int a[i];
srand(time(0));
for(i=0;i<n;i++){
k=rand()%50;
a[i]=k;
}
int gene1[n+1], gene2[n+1], gene3[n+1], gene4[n+1], gene5[n+1], gene6[n+1];
for(j=1;j<=t;j++){
for(i=0;i<n;i++){
k=rand()%kgene;
if(j==1){
gene1[i]=k;
gene4[i]=k;
}
else if(j==2){
gene2[i]=k;
gene5[i]=k;
}
if(j==3){
gene3[i]=k;
gene6[i]=k;
}
}
}
genealgeneo(gene1,gene2,gene3,gene4,gene5,gene6,n,a,kgene);
}
void genealgeneo(int gene1[],int gene2[],int gene3[],int gene4[],int gene5[],int gene6[],int n,int a[],int kgene)
{
int k;
cout<<"1st gene \n";
print(gene1,n);
cout<<"2nd gene \n";
print(gene2,n);
cout<<"3rd gene \n";
print(gene3,n);
k=rand()%6+1;
//cout<<k;
while(k--)
{
int k1=rand()%4;
int k2=rand()%4;
int sum=k1+k2;
if(sum<4)
crossover(gene1,n,gene2,n);
else if(sum==4)
crossover(gene2,n,gene2,n);
}
cout<<"\nAfter crossover \n";
cout<<"1st gene \n";
print(gene1,n);
cout<<"2nd gene \n";
print(gene2,n);
cout<<"3rd gene \n";
print(gene3,n);
int iter=4;
while(iter--){
k=rand()%6;
while(k--){
int k1=rand()%n+1;
int k3=rand()%4;
if(k3==1||k3==0)
mutation(gene1,n,k1);
else if(k3==2)
mutation(gene2,n,k1);
if(k3==3)
mutation(gene3,n,k1);
}
cout<<"\nMutation \n";
cout<<"1st gene \n";
print(gene1,n);
cout<<"2nd gene \n";
print(gene2,n);
cout<<"3rd gene \n";
print(gene3,n);
calculate_fit(a,n,gene1,kgene);
calculate_fit(a,n,gene2,kgene);
calculate_fit(a,n,gene3,kgene);
calculate_fit(a,n,gene4,kgene);
calculate_fit(a,n,gene5,kgene);
calculate_fit(a,n,gene6,kgene);
int s[6];
best_geneeneration(gene1,gene2,gene3,gene4,gene5,gene6,n,s);
for(int i=0;i<kgene;i++){
if(s[i]==gene4[n]){
replace(gene4,n,gene1,gene2,gene3,i);
}
if(s[i]==gene5[n]){
replace(gene5,n,gene1,gene2,gene3,i);
}
if(s[i]==gene6[n]){
replace(gene6,n,gene1,gene2,gene3,i);
}
}
cout<<"\n";
if(s[0]==gene1[n]) printgeneropu(a,gene1,n,kgene);
if(s[0]==gene2[n]) printgeneropu(a,gene2,n,kgene);
if(s[0]==gene3[n]) printgeneropu(a,gene1,n,kgene);
if(s[0]==gene4[n]) printgeneropu(a,gene1,n,kgene);
if(s[0]==gene5[n]) printgeneropu(a,gene2,n,kgene);
if(s[0]==gene6[n]) printgeneropu(a,gene1,n,kgene);
}
}
