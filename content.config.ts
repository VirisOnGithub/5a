import { defineContentConfig, defineCollection, z } from "@nuxt/content";

export default defineContentConfig({
  collections: {
    fifthyear: defineCollection({
      type: "page",
      source: "**",
      schema: z.object({
        date: z.string().optional(),
        image: z.string().optional(),
        color: z.string().optional(),
        description: z.string().optional(),
      }),
    }),
  },
});
