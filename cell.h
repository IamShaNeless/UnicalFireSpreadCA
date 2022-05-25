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

        int grassDensity;

    public:
        Cell(){}
        Cell(int state){ this -> actualState = state; }

        int getState() const { return this -> actualState; }
        void setState(int state){ this -> actualState = state; }
        
        int getHeight() const { return this -> height; }
        void setHeight(int height) { this -> height = height; }

        int getDensity() const { return this -> grassDensity; }
        void setDensity(int dens) { this -> grassDensity = dens; }
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


    ATTRIBUTI AGGIUNTIVI
    - gradient(Color): temporaneo; potrebbe non essere utile per l'interfaccia grafica

    - height(int): compreso tra 0 e 300. L'altezza verrà divisa in tre classi
        - tra 0 e 100:
            - 60% di probabilità di avere vegetazione di tipo CAMPO AGRICOLO
            - 40% di probabilità di avere vegetazione di tipo FORESTA
        - tra 101 e 200:
            - 80% di probabilità di avere vegetazione di tipo FORESTA
            - 20% di probabilità di avere STATO 1
        - tra 201 e 300:
            - 90% di probabilità di avere STATO 1
            - 10% di probabilità di avere vegetazione di tipo FORESTA

    - grassDensity: dipendente da height(int)
        - se tipoVegetazione è CAMPO AGRICOLO
            - grassDensity compresa tra 10 e 35
        - se tipoVegetazione è FORESTA
            - grassDensity compresa tra 36 e 75
*/


