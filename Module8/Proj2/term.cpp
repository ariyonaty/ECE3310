class Term
{
public:
    int coeff;
    int exponent;
    Term *next;
    
    Term()
    {
        next = nullptr;
    }

    Term(int c, int e)
    {
        coeff = c; 
        exponent = e;
        next = nullptr;
    }
};
