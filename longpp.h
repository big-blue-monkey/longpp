#include<iostream>
using namespace std;
namespace std{
	class longpp{
		public:
			int r[10000];
			int len;
			longpp(){
				for (int i=0;i<10000;i++){
					r[i]=0;
				}
			}
			longpp operator +(longpp &b){
				longpp a;
				a.len=len;
				for(int i=0;i<len;i++)a.r[i]=r[i];
				longpp c;
				int t;
				int x;
				c.len=max(a.len,b.len)+1;
				for(int i=0;i<c.len;i++){
					t=a.r[i]+b.r[i]+x;
					if(t>=10){
						x=1;
						t-=10;
					}else x=0;	
					c.r[i]=t;
				}
				while(c.len>0&&c.r[c.len-1]==0){
					c.len--;
				}
				return c;
			} 
		longpp operator -(longpp &b){
			longpp a;
			a.len=len;
			for(int i=0;i<len;i++)a.r[i]=r[i];
			longpp c;
			c.len=max(a.len,b.len);
			for(int i=0;i<a.len;i++){
				c.r[i]=a.r[i]-b.r[i];
				if(c.r[i]<0){
					c.r[i]=10-(0-c.r[i]);
					a.r[i+1]--;
				}
			}
			while(c.len>0&&c.r[c.len-1]==0){
				c.len--;
			}
			return c;
		}
		longpp operator*(longpp &b){
			longpp a;
			a.len=len;
			for(int i=0;i<len;i++)a.r[i]=r[i];
			longpp c;
			c.len=10000;
			if(a.r[0]==0&&a.r[0]==0){
				c.r[0]=0;
				c.len=1;
				return c; 
			}
			for(int i=0;i<a.len;i++){
				for(int j=0;j<b.len;j++){
					c.r[i+j]+=a.r[i]*b.r[j];
					c.r[i+j+1]+=c.r[i+j]/10;
					c.r[i+j]%=10;
				}
			}
			while(c.len>0&&c.r[c.len-1]==0){
				c.len--;
			}
			return c;	
		}
		bool operator==(longpp &b){
			longpp a;
			a.len=len;
			for(int i=0;i<len;i++)a.r[i]=r[i];
			if(a.len!=b.len)return 0;
			for(int i=a.len-1;i>=0;i--){
				if(a.r[i]!=b.r[i])return 0;
			}
			return 1;
		} 
		bool operator>(longpp &b){
			longpp a;
			a.len=len;
			for(int i=0;i<len;i++)a.r[i]=r[i];
			if(a.len<b.len)return 0;
			for(int i=a.len-1;i>=0;i--){
				if(a.r[i]<b.r[i])return 0;
			}
			return 1;
		} 
		longpp operator/(longpp &b){
			bool f;
			longpp a;
			a.len=len;
			for(int i=0;i<len;i++)a.r[i]=r[i];
			longpp c;
			c.len=10000;
			c.r[0]=0;
			while(1){
				c.r[0]++;
				for(int i=0;i<10000;i++){
					if(c.r[i]>10)c.r[i]-=10,c.r[i+1]+=1;
				}
				if(c*b==a)break;
				if(c*b>a){
					f=1;
					break;
				}
			}
			if(f){
				for(int i=0;i<10000;i++){
					if(c.r[i]<0)c.r[i]+=10,c.r[i+1]-=1;
				}	
			}
			while(c.len>0&&c.r[c.len-1]==0){
				c.len--;
			}
			return c;
		}
		bool operator<(longpp &b){
			longpp a;
			a.len=len;
			for(int i=0;i<len;i++)a.r[i]=r[i];
			if(a.len>b.len)return 0;
			for(int i=a.len-1;i>=0;i--){
				if(a.r[i]>b.r[i])return 0;
			}
			return 1;
		} 
	};	
} 
namespace tool{
	std::longpp read_longpp(){
		string t;
		cin>>t;
		longpp r;
		r.len=t.size();
		for(int i=t.size()-1;i>=0;i--) {
			if(!(t[i]<='9'&&t[i]>='0')){cout<<"Failed input!!!!";throw "Failed input!!!!";}
			r.r[t.size()-1-i]=t[i]-48;
		}
		while(r.len>0&&r.r[r.len-1]==0){
			r.len--;
		}
		return r;
	}
	void print_longpp(longpp &a){
		for(int i=a.len-1;i>=0;i--){
			cout<<a.r[i];
		}		
	}
	std::longpp str_to_longpp(string t){
		longpp r;
		r.len=t.size();
		for(int i=t.size()-1;i>=0;i--) {
			if(!t[i]<='9'&&!t[i]>='0')throw "Failed string!!!!";
			r.r[t.size()-1-i]=t[i]-48;
		}
		while(r.len>0&&r.r[r.len-1]==0){
			r.len--;
		}
		return r;
	}		
}
