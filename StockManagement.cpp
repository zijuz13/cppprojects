#include<iostream>
#include<cstring>
#include <list> 
#include<algorithm>
#include <iterator> 
#include <vector> 
using namespace std;
class Product{
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
    Product(int id,char* name,char* producer,char* date,double price,int amount){
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
static vector<Product> market;
bool ifExists(int id){
   bool foundOut=false;
    for(vector<Product>::iterator i=market.begin();i!=market.end();i++){
        if(id==(i->getId())){
            foundOut=true;
        }
    }
    return foundOut;
}
void showProduct(){
    cout<<"##################商品列表########################"<<endl;
        for(vector<Product>::iterator i=market.begin();i!=market.end();i++){
        cout<<"商品id:"<<i->getId()<<"\t"<<"商品名称:"<<i->getName()<<"\t"<<"商品生产商"<<i->getProducer()<<"\t"<<"商品生产日期:"<<i->getDate()<<"\t"<<"商品价格:"<<i->getPrice()<<"\t"<<"商品数量:"<<i->getAmount()<<endl;
    }
}
void showMenus(){
    cout<<"########系统菜单###########\n"<<endl;
    cout<<"      1.商品入库           "<<endl;
    cout<<"      2.商品出库           "<<endl;
    cout<<"      3.删除商品           "<<endl;
    cout<<"      4.修改商品           "<<endl;
    cout<<"      5.查询商品           "<<endl;
    cout<<"      6.浏览商品           "<<endl;
    cout<<"      7.商品统计           "<<endl;
    cout<<"      8.商品排序           "<<endl;
    cout<<"      9.退出程序           "<<endl;
}

void inputProduct(){
    int id;
    char name[15];
    char producer[15];
    char date[15];
    double price;
    int amount;
    cout<<"请输入商品id:"<<endl;
    cin>>id;
    cout<<"请输入商品名称:"<<endl;
    cin>>name;
    cout<<"请输入商品生产商:"<<endl;
    cin>>producer;
    cout<<"请输入商品生产日期"<<endl;
    cin>>date;
    cout<<"请输入商品价格"<<endl;
    cin>>price;
    cout<<"请输入商品数量"<<endl;
    cin>>amount;
    Product Product(id,name,producer,date,price,amount);
    market.push_back(Product);
    cout<<"添加成功！"<<endl;
}
void modifyProduct(){
    int id;
    char name[15];
    char producer[15];
    char date[15];
    double price;
    int amount;
    cout<<"请输入要修改的商品id:"<<endl;
    cin>>id;
    if(!ifExists(id)){
        cout<<"不存在此商品无法修改"<<endl;
        return;
    }
    cout<<"请输入商品名称:"<<endl;
    cin>>name;
    cout<<"请输入商品生产商:"<<endl;
    cin>>producer;
    cout<<"请输入商品生产日期"<<endl;
    cin>>date;
    cout<<"请输入商品价格"<<endl;
    cin>>price;
    cout<<"请输入商品数量"<<endl;
    cin>>amount;
    Product product(id,name,producer,date,price,amount);
    for(vector<Product>::iterator i=market.begin();i!=market.end();i++){
        if(id==(i->getId())){
            market.erase(i);
        }
    }
    market.push_back(product);
}
void outputProduct(){
    if(market.size()==0){
        cout<<"无法出库，请先添加商品！"<<endl;
        return;
    }
    showProduct();
    int id;
    cout<<"请输入需要出库的商品id"<<endl;
    cin>>id;
        bool foundOut=false;
        for(vector<Product>::iterator i=market.begin();i!=market.end();i++){
        if(id==(i->getId())){
            foundOut=true;
            if(0==(i->getAmount())){
                cout<<"库存不够"<<endl;
                break;
            }else{
                i->output();
                break;
            }
        }
    }
    if(foundOut){
        cout<<"商品id为"<<id<<"的商品成功出库!"<<endl;
    }
}
void deleteProduct(){
        if(market.size()==0){
        cout<<"无法删除商品，请先添加商品！"<<endl;
        return;
    }
    showProduct();
    int id;
    cout<<"请输入需要删除的商品id"<<endl;
    cin>>id;
    bool foundOut=false;
        for(vector<Product>::iterator i=market.begin();i!=market.end();i++){
        if(id==i->getId()){
            foundOut=true;
            market.erase(i);
        }
    }
    if(foundOut){
        cout<<"成功删除id为"<<id<<"的商品"<<endl;
    }else{
        cout<<"无法删除id为"<<id<<"的商品，此id在商品库存中不存在！"<<endl; 
    }
}
void searchProduct(){
    string str;
    cout<<"请输入商品名称以搜索："<<endl;
    cin>>str;
    bool foundOut=false;
   for(vector<Product>::iterator i=market.begin();i!=market.end();i++){
       string str1=i->getName();
        if(str1.find(str)!=string::npos){
            foundOut=true;
             cout<<"商品id:"<<i->getId()<<"\t"<<"商品名称:"<<i->getName()<<"\t"<<"商品生产商"<<i->getProducer()<<"\t"<<"商品生产日期:"<<i->getDate()<<"\t"<<"商品价格:"<<i->getPrice()<<"\t"<<"商品数量:"<<i->getAmount()<<endl;
        }
   }
   if(!foundOut){
    cout<<"没有找到相应的商品名称！"<<endl;
   }
}
void totalProduct(){
    int totalProducts=0;
    int totalCategories=0;
    double totalMoney=0;
        bool foundOut=false;
   for(vector<Product>::iterator i=market.begin();i!=market.end();i++){
     int amount=i->getAmount();
     double money=i->getPrice();
     totalCategories++;
     totalMoney+=amount*money;
     totalProducts+=amount;
   }
   cout<<"一共"<<totalCategories<<"种不同的商品,一共"<<totalProducts<<"件商品(总库存),总价值是："<<totalMoney<<endl;
}
static bool myCompare(const Product& a1,const Product& a2)
{
    return a1.id<=a2.id;
}
void sortProduct(){
    cout<<"按照id大小排序："<<endl;
    sort(market.begin(), market.end(), myCompare);
   showProduct();
}

int main(){
    while(true){
    int num;
    showMenus();
    cin>>num;
    bool flag=false;
    switch(num){
        case 1:{
            inputProduct();
            break;
        }
        case 2:{
         outputProduct();
         break;
        }
                case 3:{
         deleteProduct();
         break;
        }
                case 4:{
         modifyProduct();
         break;
        }
                case 5:{
         searchProduct();
         break;
        }
         case 6:{
         showProduct();
         break;
        }
         case 7:{
         totalProduct();
         break;
        }
        case 8:{
         sortProduct();
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