public class Stuff
{
    public static void main(String[] args)
    {   

    }

    public string getFile(Direction dir, string animation)
    {
        String s = "src/orc_animation/orc_" + animation + "_" + dir.toString() + ".png";
    }

    public enum Direction
    {
        northeast,
        southwest,
        northwest,
        southeast
    }
}