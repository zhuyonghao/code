#include"cylinder.h"
//���ļ��Ѿ����������༸���ļ�"��ǰĿ¼"<ϵͳĿ¼>
int main()
{
	Cylinder cy1(3.5, 6.4, 5.2, 10);
	cout << cy1;
	cout<<cy1.getX()<<" "<<cy1.getY()<<" " <<cy1.getR()
		<< cy1.getH() <<" " << cy1.area() << " " << cy1.volume();
	cout << endl;
	cy1.setH(15);//lo
	cy1.setR(7.5);
	cy1.setPoint(5, 5);
	cout << cy1;
	Point& pRef = cy1;
	cout << pRef;
	Circle& cRef = cy1;
	cout << cRef;
}