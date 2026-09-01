export function getParentPath(path: string): string {
  const cleanPath = path.length > 1 && path.endsWith('/') ? path.slice(0, -1) : path;

  const lastSlashIndex = cleanPath.lastIndexOf('/');

  if (lastSlashIndex <= 0) {
    return lastSlashIndex === 0 ? '/' : '.';
  }

  return cleanPath.slice(0, lastSlashIndex);
}
