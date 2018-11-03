class TreeNode(object):
    def __init__(self, d):
        self.data = d
        self.children = []
    
    def add_child(self, node, ):
            self.children.append(node)




class XMLTokenizer(object):
    def __init__(self, xml_str):
        self.xml = xml_str
        self.i = 0
    
    def get_next_tag(self):
        start = self.xml.find('<', self.i)
        if start == -1:
            return None
        end = self.xml.find('>', start)
        self.i = end + 1
        return self.xml[start:end + 1]
    
    def is_closed_pair(self, opened_tag, closed_tag):
        return opened_tag[1:-1] == closed_tag[2:-1]
                

class XMLTree(object):
    def __init__(self, xml_str):
        self.root = self.build_xml_tree(xml_str)

    def build_xml_tree(self, xml_str):
        xml = XMLTokenizer(xml_str)
        root_tag = xml.get_next_tag()
        return self.build_xml_tree_recur(xml, root_tag)

    def build_xml_tree_recur(self, xml, opened_tag):
        node = TreeNode(opened_tag)
        next_tag = xml.get_next_tag()
        while not xml.is_closed_pair(opened_tag, next_tag):
            # print(next_tag)
            child_node = self.build_xml_tree_recur(xml, next_tag)
            node.children.append(child_node)
            next_tag = xml.get_next_tag()
        return node

                        
    def print_tree(self):
        print_queue = []
        print_queue.append((self.root, 0))
        lvl, lvl_str = 0, ""
        while print_queue: # While is not empty
            cur_node, cur_lvl = print_queue.pop(0)
            if lvl < cur_lvl:
                print(lvl_str)
                lvl_str = ""
                lvl = cur_lvl
            for child in cur_node.children:
                lvl_str += child.data + " "
                print_queue.append((child, cur_lvl + 1))
        return





xml_str = """<html>
  <body>
    <div>
      <h1>CodeRust</h1>
      <a>http://coderust.com</a> 
    </div>
    <div>
        <h2>Chapter 1</h2>
        <h4>Chapter 1.1
            <p3></p3>
            <p4>
                <s1></s1>
            </p4>
        </h4>
    </div>
    <div>
        <h3>Chapter 2
            <p1></p1>
            <p2>
                <s></s>
            </p2>
        </h3>  
        <h4>Chapter 2.1</h4>
    </div>
  </body>
</html>"""

# xml = XMLTokenizer(xml_str)
t = XMLTree(xml_str)
t.print_tree()
