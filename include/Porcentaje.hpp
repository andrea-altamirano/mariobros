public:
    Porcentaje()
    {
        this->numero = 0
    }
    Porcentaje(int numero)
    {
        if(numero > 100 || numero < 0)
        {
            throw new std::runtime_error("Numero")
        }
        else
        {
            this -> numero = numero
        }
    }
~Porcentaje(){}
void Incrementar(int numero)
{
    this -> numero

}