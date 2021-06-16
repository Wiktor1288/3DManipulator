#ifndef VIEWERMAN_H
#define VIEWERMAN_H
#include <QGLViewer/qglviewer.h>
#include "Data.h"

///
/// \brief The ViewerMan class klasa odpowiedzialana za wyświetlenie widgetu manipulatora
/// stworzonego za pomocą OpenGL oraz QGLViewer
///

class ViewerMan:  public QGLViewer
{
public:
    ///
    /// \brief ViewerMan konstruktor inicjaizujący obiekt klasy ViewerMan
    /// \param pParent
    ///
  ViewerMan(QWidget *pParent = nullptr): QGLViewer(pParent) {}
  /// \brief dekonstruktor kalsy   ViewerMan
   ~ViewerMan();
 protected :
  ///
  /// \brief draw redefinicja metody draw() z biblioteki QGLViewer. Metoda ta odpowiada
  /// za rysowanie modelu 3D
  ///
    virtual void draw();
  ///
  /// \brief init redefinicja metody init() z biblioteki QGLViewer. Metoda ta odopowiada za inicjalizacje i ustawienie
  /// reguł rysowania za pomocą OpenGL
  ///
    virtual void init();
 public:
  ///
  /// \brief newAngles Metoda odpowiedzialana za update'owanie rysunku z nowymi wartościami kątowym
  /// \param newData Argument typu Data przechowujący dane z wartościami kątów
  ///
    void newAngles(Data newData);

 private :
    ///
    /// \brief silnik wskaźik na klase GLUquadricObj, dzieki temu obiektowi tworzony jest walec zapomocą funkcji
    /// gluCylinder w metodzie draw().
    GLUquadricObj *silnik;

    ///
    /// \brief Angles tablica przechowująca wartości poszczególnych kątów
    ///
    int Angles[3];


};

#endif // VIEWERMAN_H
