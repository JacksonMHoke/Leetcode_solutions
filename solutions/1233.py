# 1233. Remove Sub-Folders from the Filesystem
class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        foldersTrie={}
        folders=[f[1:].split('/') for f in folder]
        for fold in folders:
            curr=foldersTrie
            for name in fold:
                if 'DONE' in curr:
                    break
                if name in curr:
                    curr=curr[name]
                else:
                    curr[name]={}
                    curr=curr[name]
            curr['DONE']=True
        rt=[]
        def dfs(curr, path):
            if 'DONE' in curr:
                rt.append(path)
                return
            for name in curr:
                dfs(curr[name], path+'/'+name)
        dfs(foldersTrie, '')
        return rt