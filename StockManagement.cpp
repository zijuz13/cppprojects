#include<iostream>
#include<cstring>
#include <list> 
#include<algorithm>
#include <iterator> 
#include <vector> 
using namespace std;
class Book{
    private:
    char name[15];
    char producer[15];
    char date[15];
    double price;
    int amount;
    public:
     int id;
    void printInformation(){
        cout<<id<<name<<producer<<date<<price<<amount;
    }
    Book(int id,char* name,char* producer,char* date,double price,int amount){
        this->id=id;
        strcpy(this->name,name);
        strcpy(this->producer,producer);
        strcpy(this->date,date);
        this->price=price;
        this->amount=amount;
    }
    void setId(int id){
        this->id=id;
    }
    void output(){
        amount--;
    }
    void setName(string name){
       strcpy(this->name,name.c_str());
    }
    void setProducer(string name){
      strcpy(this->producer,producer);
    }
    void setDate(string name){
     strcpy(this->date,date);
    }
    void setPrice(double price){
        this->price=price;
    }
    void setAmount(int amount){
        this->amount=amount;
    }
    int getId(){
      return this->id; 
    }
    char* getName(){
       return this->name;
    }
    char* getProducer(){
        return this->producer;
    }
    char* getDate(){
        return this->date;
    }
    double getPrice(){
        return this->price;
    }
    int getAmount(){
        return this->amount;
    }
};
static vector<Book> market;
bool cunzai(int id){
   bool zhaodao=false;
    for(vector<Book>::iterator i=market.begin();i!=market.end();i++){
        if(id==(i->getId())){
            zhaodao=true;
        }
    }
    return zhaodao;
}
void showBook(){
    cout<<"##################书本列表########################"<<endl;
        for(vector<Book>::iterator i=market.begin();i!=market.end();i++){
        cout<<"书本id:"<<i->getId()<<"\t"<<"书本名称:"<<i->getName()<<"\t"<<"书本出版商"<<i->getProducer()<<"\t"<<"书本出版日期:"<<i->getDate()<<"\t"<<"书本价格:"<<i->getPrice()<<"\t"<<"书本数量:"<<i->getAmount()<<endl;
    }
}
void showMenus(){
    cout<<"########系统菜单###########\n"<<endl;
    cout<<"      1.书本入库           "<<endl;
    cout<<"      2.书本出库           "<<endl;
    cout<<"      3.删除书本           "<<endl;
    cout<<"      4.修改书本           "<<endl;
    cout<<"      5.查询书本           "<<endl;
    cout<<"      6.浏览书本           "<<endl;
    cout<<"      7.书本统计           "<<endl;
    cout<<"      8.书本排序           "<<endl;
    cout<<"      9.退出程序           "<<endl;
}

void inputBook(){
    int id;
    char name[15];
    char producer[15];
    char date[15];
    double price;
    int amount;
    cout<<"请输入书本id:"<<endl;
    cin>>id;
    cout<<"请输入书本名称:"<<endl;
    cin>>name;
    cout<<"请输入书本出版商:"<<endl;
    cin>>producer;
    cout<<"请输入书本出版日期"<<endl;
    cin>>date;
    cout<<"请输入书本价格"<<endl;
    cin>>price;
    cout<<"请输入书本数量"<<endl;
    cin>>amount;
    Book Book(id,name,producer,date,price,amount);
    market.push_back(Book);
    cout<<"添加成功！"<<endl;
}
void modifyBook(){
    int id;
    char name[15];
    char producer[15];
    char date[15];
    double price;
    int amount;
    cout<<"请输入要修改的书本id:"<<endl;
    cin>>id;
    if(!cunzai(id)){
        cout<<"不存在此书本无法修改"<<endl;
        return;
    }
    cout<<"请输入书本名称:"<<endl;
    cin>>name;
    cout<<"请输入书本出版商:"<<endl;
    cin>>producer;
    cout<<"请输入书本出版日期"<<endl;
    cin>>date;
    cout<<"请输入书本价格"<<endl;
    cin>>price;
    cout<<"请输入书本数量"<<endl;
    cin>>amount;
    Book Book(id,name,producer,date,price,amount);
    for(vector<Book>::iterator i=market.begin();i!=market.end();i++){
        if(id==(i->getId())){
            market.erase(i);
        }
    }
    market.push_back(Book);
}
void outputBook(){
    if(market.size()==0){
        cout<<"无法出库，请先添加书本！"<<endl;
        return;
    }
    showBook();
    int id;
    cout<<"请输入需要出库的书本id"<<endl;
    cin>>id;
        bool zhaodao=false;
        for(vector<Book>::iterator i=market.begin();i!=market.end();i++){
        if(id==(i->getId())){
            zhaodao=true;
            if(0==(i->getAmount())){
                cout<<"库存不够"<<endl;
                break;
            }else{
                i->output();
                break;
            }
        }
    }
    if(zhaodao){
        cout<<"书本id为"<<id<<"的书本成功出库!"<<endl;
    }
}
void deleteBook(){
        if(market.size()==0){
        cout<<"无法删除书本，请先添加书本！"<<endl;
        return;
    }
    showBook();
    int id;
    cout<<"请输入需要删除的书本id"<<endl;
    cin>>id;
    bool zhaodao=false;
        for(vector<Book>::iterator i=market.begin();i!=market.end();i++){
        if(id==i->getId()){
            zhaodao=true;
            market.erase(i);
        }
    }
    if(zhaodao){
        cout<<"成功删除id为"<<id<<"的书本"<<endl;
    }else{
        cout<<"无法删除id为"<<id<<"的书本，此id在书本库存中不存在！"<<endl; 
    }
}
void searchBook(){
    string str;
    cout<<"请输入书本名称以搜索："<<endl;
    cin>>str;
    bool zhaodao=false;
   for(vector<Book>::iterator i=market.begin();i!=market.end();i++){
       string str1=i->getName();
        if(str1.find(str)!=string::npos){
            zhaodao=true;
             cout<<"书本id:"<<i->getId()<<"\t"<<"书本名称:"<<i->getName()<<"\t"<<"书本出版商"<<i->getProducer()<<"\t"<<"书本出版日期:"<<i->getDate()<<"\t"<<"书本价格:"<<i->getPrice()<<"\t"<<"书本数量:"<<i->getAmount()<<endl;
        }
   }
   if(!zhaodao){
    cout<<"没有找到相应的书本名称！"<<endl;
   }
}
void totalBook(){
    int totalBooks=0;
    int totalCategories=0;
    double totalMoney=0;
        bool zhaodao=false;
   for(vector<Book>::iterator i=market.begin();i!=market.end();i++){
     int amount=i->getAmount();
     double money=i->getPrice();
     totalCategories++;
     totalMoney+=amount*money;
     totalBooks+=amount;
   }
   cout<<"一共"<<totalCategories<<"种不同的书本,一共"<<totalBooks<<"件书本(总库存),总价值是："<<totalMoney<<endl;
}
static bool myCompare(const Book& a1,const Book& a2)
{
    return a1.id<=a2.id;
}
void sortBook(){
    cout<<"按照id大小排序："<<endl;
    sort(market.begin(), market.end(), myCompare);
   showBook();
}

int main(){
    while(true){
    int num;
    showMenus();
    cin>>num;
    bool flag=false;
    switch(num){
        case 1:{
            inputBook();
            break;
        }
        case 2:{
         outputBook();
         break;
        }
                case 3:{
         deleteBook();
         break;
        }
                case 4:{
         modifyBook();
         break;
        }
                case 5:{
         searchBook();
         break;
        }
         case 6:{
         showBook();
         break;
        }
         case 7:{
         totalBook();
         break;
        }
        case 8:{
         sortBook();
         break;
        }
        case 9:{
           flag=true;
           break;
        }
        default:{
          
        }
    }
    if(true==flag){
        break;
    }
    }
    return 0;
}