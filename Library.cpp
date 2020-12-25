#include<iostream>
#include<cstring>
#include<algorithm>
#include <iterator> 
#include <vector> 
using namespace std;
//定义书本实体类
class Book{
    private:
    int id;
    char name[15];
    char producer[15];
    char date[15];
    double price;
    int amount;
    public:
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
    void output(){
        amount--;
    }
};
//用于存储图书馆库存书本
static vector<Book> library;
bool cunzai(int id){
   bool zhaodao=false;
    for(vector<Book>::iterator i=library.begin();i!=library.end();i++){
        if(id==(i->getId())){
            zhaodao=true;
        }
    }
    return zhaodao;
}
//展示所有书本
void showBook(){
    cout<<"----------------------------------书本列表------------------------------"<<endl;
        for(vector<Book>::iterator i=library.begin();i!=library.end();i++){
        cout<<"书本id:"<<i->getId()<<"\t"<<"书本名称:"<<i->getName()<<"\t"<<"书本出版商"<<i->getProducer()<<"\t"<<"书本出版日期:"<<i->getDate()<<"\t"<<"书本价格:"<<i->getPrice()<<"\t"<<"书本数量:"<<i->getAmount()<<endl;
    }
}
//展示所有菜单
void showMenus(){
    cout<<"-----------SHOWMENUS------------\n"<<endl;
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
//添加入库存
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
    library.push_back(Book);
    cout<<"恭喜你，成功添加书本到图书馆，id为："<<id<<"!"<<endl;
}
void modifyBook(){
    int id;
    char name[15];
    char producer[15];
    char date[15];
    double price;
    int amount;
    cout<<"要修改的书本id:"<<endl;
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
    Book book(id,name,producer,date,price,amount);
    for(vector<Book>::iterator i=library.begin();i!=library.end();i++){
        if(id==(i->getId())){
            library.erase(i);
        }
    }
    library.push_back(book);
}
void outputBook(){
    if(library.size()==0){
        cout<<"无法出库，请先添加书本！"<<endl;
        return;
    }
    showBook();
    int id;
    cout<<"请输入需要出库的书本id"<<endl;
    cin>>id;
        bool zhaodao=false;
        for(vector<Book>::iterator i=library.begin();i!=library.end();i++){
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
        if(library.size()==0){
        cout<<"无法删除书本，请先添加书本！"<<endl;
        return;
    }
    showBook();
    int id;
    cout<<"请输入需要删除的书本id"<<endl;
    cin>>id;
    bool zhaodao=false;
        for(vector<Book>::iterator i=library.begin();i!=library.end();i++){
        if(id==i->getId()){
            zhaodao=true;
            library.erase(i);
        }
    }
    if(zhaodao){
        cout<<"成功删除id为"<<id<<"的书本"<<endl;
    }else{
        cout<<"无法删除id为"<<id<<"的书本，此书本在图书馆中不存在!"<<endl; 
    }
}
void searchBook(){
    string str;
    cout<<"请输入书本名称以搜索："<<endl;
    cin>>str;
    bool zhaodao=false;
   for(vector<Book>::iterator i=library.begin();i!=library.end();i++){
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
   for(vector<Book>::iterator i=library.begin();i!=library.end();i++){
     int amount=i->getAmount();
     double money=i->getPrice();
     totalCategories++;
     totalMoney+=amount*money;
     totalBooks+=amount;
   }
   cout<<"书本种类："<<totalCategories<<"种,总库存："<<totalBooks<<"本,总金额："<<totalMoney<<"元；"<<endl;
}
static bool myCompare(Book& a1,Book& a2)
{
    return a1.getId()<=a2.getId();
}
void sortBook(){
    cout<<"已经按照书本的id进行升序排序，排序后的列表为："<<endl;
    sort(library.begin(), library.end(), myCompare);
   showBook();
}

int main(){
    while(true){
    int num;
    showMenus();
    cin>>num;
    bool ifExit=false;
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
           ifExit=true;
           break;
        }
        default:{
          
        }
    }
    if(true==ifExit){
        break;
    }
    }
    return 0;
}