template <typename T>
class MyVector
{
public:
    MyVector() = default;

    size_t size() const
    {
        return m_size;
    }

    void push_back(T value)
    {
        T* new_data = new T[m_size + 1];
        for(size_t i = 0 ; i < m_size; ++i)
        {
            new_data[i] = m_data[i];
        }
        new_data[m_size] = value;
        delete[] m_data;
        m_data = new_data;
        m_size += 1;
    }

    void print()
    {
        for(size_t i = 0; i < m_size; ++i)
        {
            if(i != m_size - 1)
            {
                std::cout << m_data[i] << ", ";
            }
            else
            {
                std::cout << m_data[i] << "\n";
            }
        }
    }

    void insert(T value, int m_pos)
    {
        int position = m_pos;
        int ind = 0;
        int ind_mid = false;

        T* new_data = new T[m_size + 1];
        for(size_t i = 0; i < m_size; ++i)
        {
            if(i == position)
            {
                new_data[ind] = value;
                ind += 1;
                new_data[ind] = m_data[i];
                ind_mid = true;
            }
            else
            {
                if(ind_mid == false)
                {
                    new_data[ind] = m_data[i];
                    ind += 1;
                }
                else
                {
                    new_data[ind + 1] = m_data[i];
                    ind += 1;
                }
            }
        }
        if(m_pos == m_size)
        {
            new_data[m_size] = value;
        }

    delete[] m_data;
    m_data = new_data;
    m_size += 1;
    }

    void erase(int ind1, int ind2, int ind3)
    {
        T* new_data = new T[m_size - 1];
        int j = 0;
        for(size_t i = 0; i < m_size; ++i)
        {
            if(i == ind1 || i == ind2 || i == ind3)
            {

            }
            else
            {
                new_data[j] = m_data[i];
                j++;
            }
        }
        delete[] m_data;
        m_data = new_data;
        m_size -= 3;
    }

    T& operator[](size_t index) const
    {
        return m_data[index];
    }


    ~MyVector()
    {
        delete[] m_data;
    }



private:
    T* m_data{nullptr};
    size_t m_size{0};
};