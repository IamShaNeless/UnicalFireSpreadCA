#ifndef CELL_H_
#define  CELL_H_

struct Color{
    int red;
    int green;
    int blue;

    Color(){}

    Color(int r, int g, int b):
        red(r), green(g), blue(b){}

};

class Cell{
    private:
        int actualState;
        Color gradient;
        int height;         
    public:
        Cell(){}
        Cell(int state){ this -> actualState = state; }

        int getState() const { return this -> actualState; }
        void setState(int state){ this -> actualState = state; }
        
        int getHeight() const { return this -> height; }
        void setHeight(int height) { this -> height = height; }
};


#endif

/*
    DESCRIZIONE DEL COMPORTAMENTO DELLE CELLE
    Ogni cella è caratterizzata da 4 possibili stati che evolvono
    in maniera discreta nel tempo. I possibili stati sono i seguenti:

    -Stato 1: la cella non contiene combustibile derivante da vegetazione (parti di città)
    -Stato 2: la cella contiene combustibile derivante da vegetazione che non è bruciato
    -Stato 3: la cella contiene combustibile derivante da vegetazione che sta bruciando
    -Stato 4: la cella contiene combustibile derivante da vegetzione che è stato bruciato
*/
