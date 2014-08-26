package findLevelLinkedlist;

import java.util.LinkedList;
import javax.swing.tree.TreeNode;

public class FindLevelLinkedList {
	public LinkedList<LinkedList<TreeNode>> findLevelList(TreeNode root)
	{
		int level = 0;
		LinkedList<LinkedList<TreeNode>> results = new LinkedList<LinkedList<TreeNode>>();
		LinkedList<TreeNode> list = new LinkedList<TreeNode>();
		
		list.add(root);
		results.add(level, list);
		
		while(true)
		{
			list = new LinkedList<TreeNode>();
			for(int i = 0; i < results.get(level).size(); i ++)
			{
				TreeNode tmp = results.get(level).get(i);
				if(tmp != null)
				{
					if(tmp.getChildAt(0) != null)
						list.add(tmp.getChildAt(0));
					if(tmp.getChildAt(1) != null)
						list.add(tmp.getChildAt(1));
				}
			}
			
			if(list.size() > 0)
				results.add(++ level, list);
			else
				break;
		}
		return results;
	}
	
	
}
