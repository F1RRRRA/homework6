template <typename T>
class MyList
{
public:
    MyList() : m_last{}, m_size{0} {}

    struct Node
    {
        Node* next;
        Node* prev;
        T data;
    };
    
    size_t size() const
    {
        return m_size;
    }


    void push_back(T value)
    {
        Node* new_node = new Node{};
        new_node->prev = m_last;
        new_node->next = nullptr;
        new_node->data = value;
        if(m_size == 0)
        {
            m_first = new_node;
        }
        else
            m_last->next = new_node;
        m_last = new_node;    
        m_size += 1;
    }

    void print()
    {
        m_last = m_first;
        for(size_t i = 0; i < m_size; ++i)
        {
            if(i != m_size - 1)
            {
                std::cout << m_last->data << ", ";
                m_last = m_last->next;
            }
            else
            {
                std::cout << m_last->data << "\n";
            }
        }
    }

    T& operator[](int ind)
    {
        m_last = m_first;
        for(size_t i = 0; i < m_size; ++i)
        {
            m_last = m_last->next;
        }
        return m_last->data;
    }

    void erase(int ind)
    {
        m_last = m_first;
        for(size_t i = 0; i < m_size; ++i)
        {
            if(i == ind)
            {
                tmp = m_last;
                Node* tmp_Node = m_last->next;
                tmp_Node->next = tmp->next->next;
                tmp_Node->next->next->prev = tmp_Node;
                m_last->prev->next = tmp_Node;
                m_size -= 1;
            }

            m_last = m_last->next;
        }
    }

    void insert(T value, int m_pos)
    {
        m_end = m_last;
        m_last = m_first;
        Node* newNode = new Node{};
        newNode->data = value;
        if(m_pos == 0)
        {
            newNode->next = m_last;
            m_last->prev = newNode;
            newNode->prev = nullptr;
            m_first = newNode;
            m_size += 1;
        }
        if(m_pos > 0 && m_pos < m_size-1)
        {
            for(size_t i = 0; i < m_size; ++i)
            {
                if(i == m_pos)
                {
                    newNode->next = m_last;
                    newNode->prev = m_last->prev;
                    tmp = newNode;
                    m_last->prev = tmp;
                    m_last->prev->prev->next = tmp;     //происходит замена значения на этой позиции на наше значение
                    m_size += 1;
                }
                if(m_last->next != nullptr)
                {
                    m_last = m_last->next;
                }
            }
        }
        if(m_pos == m_size)
        {
           newNode->next = nullptr;
           m_end->next = newNode;
           newNode->prev = m_end;
           m_last = m_end;
           m_size += 1; 
        }
    }

    ~MyList()
    {
        delete[] m_last;
    }



private:
    size_t m_size;
    Node* m_last;
    Node* m_first;
    Node* tmp;
    Node* m_end;
};