package uk.co.jigglesoft.tool.font2src.model;

import java.awt.*;
import java.io.File;
import java.io.IOException;

public class BitMap
{
    private final String id;

    private final String filePath;

    private final Image image;


    public static String getFilePath(final File file) throws IOException
    {
        return file.getAbsoluteFile().getCanonicalPath();
    }


    public BitMap(final String id, final File file, final Image image) throws IOException
    {
        this.id = id;
        this.filePath = getFilePath(file);
        this.image = image;
    }


    public String getId()
    {
        return id;
    }

    public String getPath()
    {
        return filePath;
    }
}
