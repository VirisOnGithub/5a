export interface ContentItem {
  [key: string]: unknown;
  title: string;
  path: string;
  stem?: string;
  page?: false;
  image?: string;
  children?: ContentItem[];
  color?: string;
}

export const useAsyncClassData = async (children: boolean): Promise<Ref<ContentItem[]>> => {
  const { data: navigation } = await useAsyncData(children ? "navigation-c": "navigation", () => {
      const allData = queryCollectionNavigation("class", ["image", "color"])
      return (
        children ? allData : allData.then((items) => items.map(({ children, ...rest }) => rest))
      );
  }, {default: () => []});
  return navigation
}
