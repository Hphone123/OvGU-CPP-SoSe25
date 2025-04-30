public class ArrayList
{

    private int         cap = 2;
    private int         size = 0;
    private Integer []  elements = new Integer[cap];

    // Return the current number of elements.
    public int size()
    {
        return this.size;
    }
    // Return the currently available size.
    public int capacity()
    {
        return this.cap;
    }
    // Construct a new ArrayList with some space.
    public ArrayList()
    {
        // ...
    }
    // Increase the capacity to hold at least newSize elements.
    // This method never decreases the size of the ArrayList!
    public void reserve(int newSize)
    {
        if (newSize < this.size)
            return;

        Integer [] tmp = new Integer[newSize];
        System.arraycopy(this.elements, 0, tmp, 0, this.size);
        this.elements = tmp;
        this.cap = newSize;

    }
    // Add an element to the back of the ArrayList.
    public void push_back(int element)
    {
        if (this.size >= this.cap) {
            reserve(this.size * this.size);
        }

        this.elements[this.size++] = element;
    }
    // Remove the last element from the ArrayList.
    public void pop_back()
    {
        this.size--;
    }
    // Return the value at the given position.
    public int get_at(int index)
    {
        if (index >= this.size)
            return 0;
        return this.elements[index];
    }

    // Set the value at the given position.
    public void set_at(int index, int element)
    {
        if (index >= this.size)
            return;

        this.elements[index] = element;
    }

    // Insert the element at the given index. 
    // The elements after that position are shifted towards the back.
    public void insert(int index, int element)
    {
        if (index > this.size)
            return;

        if (this.size >= this.cap) 
            reserve(this.size * this.size);

        for (int i = this.size; i > index; i--) 
        {
            this.elements[i] = this.elements[i-1];
        }

        this.elements[index] = element;
        this.size++;

    }
    // Erase a block of elements of size length, starting at index.
    // The elements following this block are shifted towards the front.
    public void erase(int index, int length)
    {
        if (index >= this.size)
            return;
        
        for (int i = index; i < this.size; i++) 
        {
            this.elements[i] = this.elements[i + length];
        }

        this.size -= length;
    }
}