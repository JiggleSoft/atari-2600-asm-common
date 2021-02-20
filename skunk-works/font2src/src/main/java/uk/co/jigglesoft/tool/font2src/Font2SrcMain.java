package uk.co.jigglesoft.tool.font2src;

public class Font2SrcMain
{
    public static final String VERSION_STRING = "0.0.0-beta-0";

    public static void printJiggleSoftLogo()
    {
        System.out.println(
"     _ _             _      ____         __ _\n" +
"    | (_) __ _  __ _| | ___/ ___|  ___  / _| |_\n" +
" _  | | |/ _` |/ _` | |/ _ \\___ \\ / _ \\| |_| __|\n" +
"| |_| | | (_| | (_| | |  __/___) | (_) |  _| |_ \n" +
" \\___/|_|\\__, |\\__, |_|\\___|____/ \\___/|_|  \\__|\n" +
"          |___/ |___/"
        );
    }

    public static void printApplicationName()
    {
        System.out.println(
"    ______            __       ___       _____\n" +
"   / ____/___  ____  / /_     |__ \\     / ___/____  __  _______________\n" +
"  / /_  / __ \\/ __ \\/ __/_______/ /_____\\__ \\/ __ \\/ / / / ___/ ___/ _ \\\n" +
" / __/ / /_/ / / / / /_/_____/ __/_____/__/ / /_/ / /_/ / /  / /__/  __/\n" +
"/_/    \\____/_/ /_/\\__/     /____/    /____/\\____/\\__,_/_/   \\___/\\___/"
                          );
    }

    public static void printVersion()
    {
        System.out.println("Version: " + VERSION_STRING);
    }

    public static void main(final String[] args)
    {
        printJiggleSoftLogo();
        System.out.println("\nPresents\n");
        printApplicationName();
        System.out.println("\n\n");
        printVersion();
    }
}
