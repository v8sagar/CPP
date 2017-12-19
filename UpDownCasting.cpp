#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

namespace NShape
{
	enum ShapeType
	{
		EXIT, RECTANGLE, CIRCLE
	};
	class Shape
	{
	protected:
		float area;
	public:
		Shape ( void )throw( ) : area( 0 )
		{	}
		virtual void calculateArea( void )throw( ) = 0;
		float getArea() const
		{
			return area;
		}
		virtual ~Shape( void ){	}
	};
	class Rectangle : public Shape
	{
	private:
		float length;
		float breadth;
	public:
		Rectangle( void ) throw( ) : length( 0 ), breadth( 0 )
		{	}
		void setLength(float length)
		{
			this->length = length;
		}
		void setBreadth(float breadth)
		{
			this->breadth = breadth;
		}
		void calculateArea( void )throw( )
		{
			this->area = this->length * this->breadth;
		}
	};
	class Math
	{
	public:
		static const float PI;
	public:
		static float power( float base, int index )
		{
			float result = 1;
			for( int count = 1; count <= index; ++ count )
				result = result * base;
			return result;
		}
	};
	const float Math::PI = 3.14f;
	class Circle : public Shape
	{
	private:
		float radius;
	public:
		Circle( void ) : radius( 0 )
		{	}
		void setRadius(float radius)
		{
			this->radius = radius;
		}
		void calculateArea( void )throw( )
		{
			this->area = Math::PI * Math::power(this->radius, 2 );
		}
	};
	class ShapeFactory
	{
	public:
		static Shape* getInstance( ShapeType choice )
		{
			Shape* ptrShape = NULL;
			switch( choice )
			{
			case RECTANGLE:
				ptrShape = new Rectangle();	//Upcasting
				break;
			case CIRCLE:
				ptrShape = new Circle();	//Upcasting
				break;
			}
			return ptrShape;
		}
	};
}
using namespace NShape;
void accept_record( Shape* ptrShape )
{
	if( dynamic_cast<Rectangle*>( ptrShape ) != NULL )
	{
		Rectangle* ptrRectangle = dynamic_cast<Rectangle*>( ptrShape );//Downcasting

		float length;
		cout<<"Length	:	";
		cin>>length;
		ptrRectangle->setLength( length );

		float breadth;
		cout<<"Breadth	:	";
		cin>>breadth;
		ptrRectangle->setBreadth( breadth );
	}
	else
	{
		Circle* ptrCircle = dynamic_cast<Circle*>( ptrShape );//Downcasting
		float radius;
		cout<<"Radius	:	";
		cin>>radius;
		ptrCircle->setRadius( radius );
	}
}
void print_record( Shape* ptrShape )
{
	string name = typeid( *ptrShape ).name( );	//RTTI
	cout<<"Area of instance of "<<name<<" is : "<<ptrShape->getArea()<<endl;
}
ShapeType menu_list( void )
{
	int choice;
	cout<<"0.Exit."<<endl;
	cout<<"1.Rectangle."<<endl;
	cout<<"2.Circle"<<endl;
	cout<<"Enter choice	:	";
	cin>>choice;
	return ShapeType( choice );
}
int main( void )
{
	ShapeType choice;
	while( ( choice = ::menu_list( ) ) != EXIT )
	{
		Shape* ptrShape = ShapeFactory::getInstance( choice );
		if( ptrShape != NULL )
		{
			::accept_record( ptrShape );
			ptrShape->calculateArea( );
			::print_record( ptrShape );
			delete ptrShape;
		}
	}
	return 0;
}
