package pov

type Tree struct {
	// Add the needed fields here
	parent *Tree
	child  *Tree
	next   *Tree
	value  string
}

// New creates and returns a new Tree with the given root value and children.
func New(value string, children ...*Tree) *Tree {
	tree := &Tree{
		value:  value,
		child:  nil,
		parent: nil,
		next:   nil,
	}

	if len(children) == 0 {
		return tree
	}

	// Children linked list
	head := children[0]
	curr := head
	curr.parent = tree

	for _, child := range children[1:] {
		child.parent = tree
		curr.next = child
		curr = curr.next
	}

	tree.child = head

	return tree
}

// Value returns the value at the root of a tree.
func (tr *Tree) Value() string {
	return tr.value
}

// Children returns a slice containing the children of a tree.
// There is no need to sort the elements in the result slice,
// they can be in any order.
func (tr *Tree) Children() []*Tree {
	var result []*Tree

	for child := tr.child; child != nil; child = child.next {
		result = append(result, child)
	}

	return result
}

// String describes a tree in a compact S-expression format.
// This helps to make test outputs more readable.
// Feel free to adapt this method as you see fit.
func (tr *Tree) String() string {
	if tr == nil {
		return "nil"
	}
	result := tr.Value()
	if len(tr.Children()) == 0 {
		return result
	}
	for _, ch := range tr.Children() {
		result += " " + ch.String()
	}
	return "(" + result + ")"
}

// POV problem-specific functions

func (tr *Tree) find(to string) *Tree {
	if tr.value == to {
		return tr
	}
	for child := tr.child; child != nil; child = child.next {
		if found := child.find(to); found != nil {
			return found
		}
	}
	return nil
}

func (tr *Tree) removeChild(child *Tree) {
	for child_ptr := &tr.child; *child_ptr != nil; child_ptr = &(*child_ptr).next {
		if (*child_ptr) == child {
			(*child_ptr) = child.next
			child.next = nil
			child.parent = nil
			return
		}
	}
}

func (tr *Tree) appendChild(child *Tree) {
	child.parent = tr
	child.next = tr.child
	tr.child = child
}

// FromPov returns the pov from the node specified in the argument.
func (tr *Tree) FromPov(from string) *Tree {
	pov := tr.find(from)
	if pov == nil {
		return nil
	}
	for child, parent := pov, pov.parent; parent != nil; {
		grandparent := parent.parent
		if grandparent != nil {
			grandparent.removeChild(parent)
		}
		parent.removeChild(child)
		child.appendChild(parent)
		child = parent
		parent = grandparent
	}
	return pov
}

// PathTo returns the shortest path between two nodes in the tree.
func (tr *Tree) PathTo(from, to string) []string {
	root := tr.FromPov(to)
	if root == nil {
		return nil
	}
	var result []string
	for child := root.find(from); child != nil; child = child.parent {
		result = append(result, child.value)
	}
	return result
}
