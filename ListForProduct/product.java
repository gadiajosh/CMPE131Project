
/**
 * Write a description of class list here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class product
{
    private int number;
    private int quality;
    private int thePrice;
    private String theProduct;
    private String theOwner;
    public product(){
        number = 0;
        thePrice = 0;
        quality = 0;
        theProduct = null;
        theOwner = null;
    }
    
    public product(String theOwner, int number, String theProduct, int thePrice, int quality)
    {
        this.number = number;
        this.quality = quality;
        this.thePrice = thePrice;
        this.theProduct = theProduct;
        this.theOwner = theOwner;
    }
    
    public String owner(){
        return theOwner;
    }
    public String theProduct(){
        return theProduct;
    }
    public int number(){
        return number;
    }
    public int quality(){
        return quality;
    }
    public int thePrice(){
        return thePrice;
    }
    public String toString()
    {
        return "Product[sellers name is "+owner()+",the product is "+theProduct()+",the number is "+number()+",the quality is "+quality()+"the price is "+thePrice()+"]";
    }
}
