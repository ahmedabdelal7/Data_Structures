using System;
using System.Collections.Generic;


namespace GeneralTreeExample
{
    public class TreeNode<T>
    {
        public T Value { get; set; }
        public List<TreeNode<T>> Children { get; set; }


        public TreeNode(T value)
        {
            this.Value = value;
            Children = new List<TreeNode<T>>();
        }


        public void AddChild(TreeNode<T> child)
        {
            Children.Add(child);
        }
    }


    public class Tree<T>
    {
        public TreeNode<T> Root { get; private set; }


        public Tree(T rootValue)
        {
            Root = new TreeNode<T>(rootValue);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Creating the tree level 0:
            var CompanyTree = new Tree<string>("CEO");

            // Adding departments to the CEO node
            var financeNode = new TreeNode<string>("Finance");
            var techNode = new TreeNode<string>("Technology");
            var marketingNode = new TreeNode<string>("Marketing");

            CompanyTree.Root.AddChild(financeNode);
            CompanyTree.Root.AddChild(techNode);
            CompanyTree.Root.AddChild(marketingNode);

            // Adding Employees to Finance Department
            financeNode.AddChild(new TreeNode<string>("Accountant"));
            financeNode.AddChild(new TreeNode<string>("Financial Analyst"));

            // Adding Specializations to Technology Department
            var backendNode = new TreeNode<string>("Backend");
            var frontendNode = new TreeNode<string>("Frontend");

            techNode.AddChild(backendNode);
            techNode.AddChild(frontendNode);

            //Add Employees to Technology Specializations
            backendNode.AddChild(new TreeNode<string>("C# Developer"));
            backendNode.AddChild(new TreeNode<string>("Database Developer"));
            frontendNode.AddChild(new TreeNode<string>("UI Developer"));

            //Add Specializations to Marketing Node
            marketingNode.AddChild(new TreeNode<string>("Social Media"));
            marketingNode.AddChild(new TreeNode<string>("Content Creator"));



            // Printing the tree
            PrintTree(CompanyTree.Root);

            Console.ReadKey();
        }

        public static void PrintTree<T>(TreeNode<T> node, string indent = " ")
        {
            Console.WriteLine(indent + node.Value);
            foreach (var child in node.Children)
            {
                PrintTree(child, indent + "  ");
            }
        }
    }
}
