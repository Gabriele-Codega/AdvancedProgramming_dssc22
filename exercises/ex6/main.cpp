#include<cmath>
#include <iostream>
#include <memory>


//vertex class, templated
template<typename T>
class Vertex{
public:
  T x;
  T y;

  Vertex():x(0),y(0){};
  Vertex(const T& a,const T& b):x(a),y(b){};
};

//compute the distance between two vertices (points)
template<typename T>
double distance(const Vertex<T>& a, const Vertex<T>& b){
  return std::sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

//base shape class
class Shape{
public:
  virtual double perimeter(){return 0;}
  virtual void print_vertices(){}
  virtual ~Shape(){std::cout<<"shape destr"<<std::endl;};
};

//triangle, derived from shape
// templated since the vertices require a template
template<typename T>
class Triangle: public Shape{
public:
  Vertex<T> a;
  Vertex<T> b;
  Vertex<T> c;

  // constructor, taking three vertices
  Triangle(const Vertex<T>& x,const Vertex<T>& y,const Vertex<T>& z){
    a = x;
    b = y;
    c = z;
  }

  // perimeter, overridden from shape
  double perimeter() override {
    auto d1 = distance<T>(a,b);
    auto d2 = distance<T>(b,c);
    auto d3 = distance<T>(a,c);

    return d1+d2+d3;
  }

  // printing vertices, overridden from shape
  // could be prettier if there was a function to print vertices
  void print_vertices() override {
    std::cout<<"a = "<<a.x<<","<<a.y<<std::endl;
    std::cout<<"b = "<<b.x<<","<<b.y<<std::endl;
    std::cout<<"c = "<<c.x<<","<<c.y<<std::endl;
  }

  // destructor
  ~Triangle(){std::cout<<"triangle destr"<<std::endl;}
};

template<typename T>
class Polygon: public Shape{
public:
  int n;
  Vertex<T>* vertices;

  Polygon(const int& N){
    vertices = new Vertex<double>[N];
    n = N;
  }


  void addVertex(int i, const Vertex<T>& a){
    vertices[i] = a;
    std::cout<<"called standard"<<std::endl;
  }
  template<typename... Types>
  void addVertex(int i,const Vertex<T>& a, const Types&... args){
    std::cout<<"called variadic"<<std::endl;
    vertices[i] = a;
    i++;
    addVertex(i,args...);
  }

  ~Polygon(){
    delete[] vertices;
    std::cout<<"polygon destr"<<std::endl;
  };

  double perimeter() override{
    std::unique_ptr<double[]> distances(new double[n]);
    double perim{0};

    for(int i=0;i<n;++i){
      distances[i] = distance(vertices[i],vertices[(i+1)%n]);
    }
    for(int i=0;i<n;++i){
      perim += distances[i];
    }
    return perim;
  }

  void print_vertices() override{
    for(int i=0;i<n;++i){
      std::cout<<vertices[i].x<<","<<vertices[i].y<<"--";
    }
    std::cout<<std::endl;
  }

};


int main(){
  Vertex<double> a(0,0);
  Vertex<double> b(1,0);
  Vertex<double> c(1,1);
  Vertex<double> d(0,1);
  Triangle<double>* t = new Triangle<double>(a,b,c);
  Polygon<double>* q = new Polygon<double>(4);
  Shape* s1 = t;
  Shape* s2 = q;

  std::cout<<s1->perimeter()<<std::endl;
  s1->print_vertices();

  delete s1;


  q->addVertex(0,a,b,c,d);
  std::cout<<q->perimeter()<<std::endl;
  q->print_vertices();

  delete q;

  return 0;
}
