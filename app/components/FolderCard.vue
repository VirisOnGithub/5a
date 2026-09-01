<script setup lang="ts">
const props = defineProps<{ item: ContentItem }>();
</script>

<template>
    <NuxtLink :to="item.path">
        <UCard class="group overflow-hidden relative border-0 bg-gray-900">
            <div class="relative h-80 w-full overflow-hidden">
                <img
                    v-if="item.image"
                    :src="item.image"
                    alt="Illustration"
                    class="h-full w-full object-cover object-center transition-transform duration-700 ease-out group-hover:scale-105"
                />

                <div
                    v-else-if="item.color"
                    class="h-full w-full object-cover object-center"
                    :style="`background-color: ${item.color}`"
                />

                <div
                    class="absolute inset-0 bg-linear-to-t from-gray-950 via-gray-950/40 to-transparent opacity-80 transition-opacity duration-300 group-hover:opacity-70"
                />

                <div
                    class="absolute bottom-0 left-0 right-0 p-6 z-10 space-y-3"
                >
                    <h3
                        class="text-2xl font-black tracking-tight text-white leading-snug drop-shadow-sm group-hover:text-emerald-200 transition-colors duration-300"
                    >
                        {{ item.title }}
                    </h3>
                </div>
            </div>
        </UCard>
    </NuxtLink>
</template>
